/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <math.h>

#include <algorithm>
#include <set>
#include <utility>

#include "src/arena.h"
#include "src/arena_params.h"
#include "src/event_collision.h"
#include "src/event_distress.h"
#include "src/event_entity_type.h"
#include "src/event_recharge.h"
#include "src/game_state.h"
#include "src/home_base.h"
#include "src/obstacle.h"
#include "src/player.h"
#include "src/recharge_station.h"
#include "src/robot.h"
#include "src/sensor_proximity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params *const params)
    : game_state_(GAME_RUNNING), x_min_(params->x_min), y_min_(params->y_min),
      x_max_(params->x_dim), y_max_(params->y_dim),
      player_(new Player(&params->player)),
      recharge_station_(new RechargeStation(params->recharge_station.radius,
                                            params->recharge_station.pos,
                                            params->recharge_station.color)),
      home_base_(new HomeBase(&params->home_base)), entities_(),
      mobile_entities_(), sensors_() {
    player_->set_heading_angle(-143);
    entities_.push_back(player_);
    mobile_entities_.push_back(player_);
    RegisterSensor(player_->get_sensor_touch());

    entities_.push_back(recharge_station_);

    entities_.push_back(home_base_);
    mobile_entities_.push_back(home_base_);

    for (size_t i = 0; i < params->n_obstacles; ++i) {
        entities_.push_back(new Obstacle(params->obstacles[i].radius,
                                         params->obstacles[i].pos,
                                         params->obstacles[i].color));
    } /* for(i..) */

    for (size_t i = 0; i < params->n_robots; ++i) {
        auto robot = new Robot(&params->robots[i]);
        entities_.push_back(robot);
        mobile_entities_.push_back(robot);

        // register all the sensors for this robot
        RegisterSensor(robot->get_sensor_distress());
        RegisterSensor(robot->get_sensor_entity_type());
        RegisterSensor(robot->get_sensor_proximity_left());
        RegisterSensor(robot->get_sensor_proximity_right());
        RegisterSensor(robot->get_sensor_touch());
    }
}

Arena::~Arena(void) {
    for (auto ent : entities_) {
        delete ent;
    }
}

void Arena::Reset(void) {
    game_state_ = GAME_RUNNING;
    for (auto ent : entities_) {
        ent->Reset();
    } /* for(ent..) */
} /* reset() */

std::vector<Obstacle *> Arena::get_obstacles(void) {
    std::vector<Obstacle *> res;
    for (auto ent : entities_) {
        Obstacle *o = dynamic_cast<Obstacle *>(ent);
        if (o) {
            res.push_back(o);
        }
    } /* for(ent..) */
    return res;
} /* robots() */

std::vector<Robot *> Arena::get_robots(void) {
    std::vector<Robot *> res;
    for (auto ent : mobile_entities_) {
        Robot *r = dynamic_cast<Robot *>(ent);
        if (r) {
            res.push_back(r);
        }
    }
    return res;
}

void Arena::AdvanceTime(double dt) {
    // std::cout << "Advancing simulation time by " << dt << " timesteps\n";
    // for (size_t i = 0; i < 1; ++i) {
    //     UpdateEntitiesTimestep();
    // } /* for(i..) */
    UpdateEntitiesTimestep(dt);
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep(double dt) {
    /*
     * First, update the position of all entities, according to their current
     * velocities.
     */
    for (auto ent : entities_) {
        ent->TimestepUpdate(dt);
    } /* for(ent..) */

    /*
     * Next, check if the player has run out of battery
     */
    if (player_->get_battery_level() <= 0) {
        game_state_ = GAME_LOSE;
    }

    // sensor touch
    for (auto ent : mobile_entities_) {
        // check if it's out of bounds
        EventCollision ec;
        CheckForEntityOutOfBounds(ent, &ec);
        if (ec.get_collided()) {
            ent->get_sensor_touch()->Accept(&ec);
        }

        Robot *r = dynamic_cast<Robot *>(ent);
        SensorDistress *sd;
        SensorEntityType *st;
        if (r) {
            // distress sensor
            if (r->get_frozen()) {
                EventDistress ed;
                for (auto s : sensors_) {
                    sd = dynamic_cast<SensorDistress *>(s);
                    if (!sd)
                        continue;
                    if (r->get_pos().to(sd->get_parent()->get_pos()) >
                        SENSING_RANGE)
                        continue;
                    sd->Accept(&ed);
                }
            }

            // entity type sensor
            for (auto s : sensors_) {
                EventEntityType et(r->get_entity_type());
                st = dynamic_cast<SensorEntityType *>(s);
                if (!st)
                    continue;
                if (r->get_pos().to(st->get_parent()->get_pos()) >
                    SENSING_RANGE)
                    continue;
                st->Accept(&et);
            }
        }
    }

    std::set<std::pair<class ArenaMobileEntity *, class ArenaEntity *>> visited;

    for (auto ent1 : mobile_entities_) {
        for (auto ent2 : entities_) {
            if (ent1 == ent2 || ent2 == player_)
                continue;
            ArenaMobileEntity *ent2m = dynamic_cast<ArenaMobileEntity *>(ent2);
            Player *ent1p = dynamic_cast<Player *>(ent1);
            Robot *ent1r = dynamic_cast<Robot *>(ent1),
                  *ent2r = dynamic_cast<Robot *>(ent2);
            if (ent2m &&
                visited.find(std::make_pair(ent2m, ent1)) != visited.end())
                continue;

            // collision sensor
            EventCollision ec;
            CheckForEntityCollision(ent1, ent2, &ec,
                                    ent1->get_collision_delta());
            // check for collision between any two entities
            if (ec.get_collided()) {
                printf("found collision! contestants: '%s' and '%s'\n",
                       ent1->get_name().c_str(), ent2->get_name().c_str());
                EventCollision *op = ec.opposite();
                EventRecharge e;
                if (ent1 == player_ && ent1p) {
                    printf("commencing special cases wao \n");
                    // some special cases!
                    switch (ent2->get_entity_type()) {
                    case kRobot:
                        // send the collision to the player
                        ent1->get_sensor_touch()->Accept(&ec);
                        // robot freezes
                        if (!ent2m->get_frozen())
                            ent2m->set_frozen(-1);  // doesn't unfreeze itself
                        break;
                    case kSuperBot:
                        // player gets frozen
                        ent1->set_frozen(5);
                        // super bot bounces off instead
                        ent2m->get_sensor_touch()->Accept(op);
                        break;
                    case kRechargeStation:
                        // recharge player
                        ent1p->Accept(&e);
                        goto default_collide_;
                    default:
                        goto default_collide_;
                    }
                } else {
                    Robot *bot;
                    ArenaEntity *other;
                    if (ent1->get_entity_type() == kRobot ||
                        ent1->get_entity_type() == kSuperBot) {
                        bot = ent1r;
                        other = ent2;
                    } else if (ent2->get_entity_type() == kRobot ||
                               ent2->get_entity_type() == kSuperBot) {
                        bot = ent2r;
                        other = ent1;
                    } else {
                        goto default_collide_;
                    }
                    ArenaMobileEntity *otherm =
                        dynamic_cast<ArenaMobileEntity *>(other);

                    if (bot->get_frozen())
                        goto done_collide_;
                    switch (other->get_entity_type()) {
                    case kHomeBase:
                        bot->upgrade();
                        goto default_collide_;
                    case kRobot:
                        if (otherm->get_frozen())
                            otherm->dec_fcountdown(0);  // unfreezes if < 0
                        goto default_collide_;
                    default:
                        goto default_collide_;
                    }
                }
            default_collide_:
                ent1->get_sensor_touch()->Accept(&ec);
                if (ent2m) {
                    ent2m->get_sensor_touch()->Accept(op);
                }
                delete op;
            }

        done_collide_:
            // proximity sensor
            EventProximity ep;
            Robot *r1 = dynamic_cast<Robot *>(ent1),
                  *r2 = dynamic_cast<Robot *>(ent2);
            if (r1) {
                CheckProximity(r1, r1->get_sensor_proximity_left(), ent2, &ep);
                if (ep.get_activated())
                    r1->get_sensor_proximity_left()->Accept(&ep);
                CheckProximity(r1, r1->get_sensor_proximity_right(), ent2, &ep);
                if (ep.get_activated())
                    r1->get_sensor_proximity_right()->Accept(&ep);
            }
            if (r2) {
                CheckProximity(r2, r2->get_sensor_proximity_left(), ent1, &ep);
                if (ep.get_activated())
                    r2->get_sensor_proximity_left()->Accept(&ep);
                CheckProximity(r2, r2->get_sensor_proximity_right(), ent1, &ep);
                if (ep.get_activated())
                    r2->get_sensor_proximity_right()->Accept(&ep);
            }

            visited.insert(std::make_pair(ent1, ent2));
        }
    }

    // check if there is a victory
    auto robots = get_robots();
    int remain = 0;
    for (auto robot : robots) {
        if (robot->get_entity_type() == kRobot && !robot->get_frozen())
            remain++;
    }
    if (!remain) {
        set_game_state(GAME_WIN);
    }
} /* UpdateEntities() */

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity *const ent,
                                      EventCollision *event) {
    csci3081::Position epos = ent->get_pos();
    double radius = ent->get_radius(), heading_angle = ent->get_heading_angle();

    if (epos.x + radius >= x_max_) {
        // Right Wall
        event->set_collided(true);
        event->set_point_of_contact(Position(epos.x + radius, epos.y));
        event->set_angle_of_contact(180 + heading_angle);
    } else if (epos.x - radius <= x_min_) {
        event->set_collided(true);
        event->set_point_of_contact(Position(epos.x - radius, epos.y));
        event->set_angle_of_contact(180 + heading_angle);
    } else if (epos.y + radius >= y_max_) {
        // Bottom Wall
        event->set_collided(true);
        event->set_point_of_contact(Position(epos.x, epos.y + radius));
        event->set_angle_of_contact(heading_angle);
    } else if (epos.y - radius <= y_min_) {
        // Top Wall
        event->set_collided(true);
        event->set_point_of_contact(Position(epos.x, epos.y - radius));
        event->set_angle_of_contact(heading_angle);
    } else {
        event->set_collided(false);
    }
} /* entity_out_of_bounds() */

void Arena::CheckForEntityCollision(const ArenaEntity *const ent1,
                                    const ArenaEntity *const ent2,
                                    EventCollision *const event,
                                    double collision_delta) {
    /* Note: this assumes circular entities */
    double ent1_x = ent1->get_pos().x;
    double ent1_y = ent1->get_pos().y;
    double ent2_x = ent2->get_pos().x;
    double ent2_y = ent2->get_pos().y;
    double ent1_r = ent1->get_radius();

    double dist =
        std::sqrt(std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));
    if (dist > ent1->get_radius() + ent2->get_radius() + collision_delta) {
        event->set_collided(false);
    } else {
        event->set_collided(true);

        double angle = std::asin(std::abs(ent2_x - ent1_x) / dist);

        if ((ent2_x - ent1_x) > 0) {
            if ((ent2_y - ent1_y) > 0) {
                // lower right
                event->set_point_of_contact(
                    {ent1_x + std::sin(angle) * ent1_r,
                     ent1_y + std::cos(angle) * ent1_r});
                angle = M_PI_2 - angle;
            } else if ((ent2_y - ent1_y) < 0) {
                // upper right
                event->set_point_of_contact(
                    {ent1_x + std::sin(angle) * ent1_r,
                     ent1_y - std::cos(angle) * ent1_r});
                angle += (3 * M_PI_2);
            } else {  // if ((ent2_y - ent1_y) == 0)
                // 0 or 360 deg
                event->set_point_of_contact({ent1_x + ent1_r, ent1_y});
                angle = 0;
            }
        } else if ((ent2_x - ent1_x) < 0) {
            if ((ent2_y - ent1_y) > 0) {
                // lower left
                event->set_point_of_contact(
                    {ent1_x - std::sin(angle) * ent1_r,
                     ent1_y + std::cos(angle) * ent1_r});
                angle += M_PI_2;
            } else if ((ent2_y - ent1_y) < 0) {
                // upper left
                event->set_point_of_contact(
                    {ent1_x - std::sin(angle) * ent1_r,
                     ent1_y - std::cos(angle) * ent1_r});
                angle = (M_PI_2 * 2) + (M_PI_2 - angle);
            } else {  // if ((ent2_y - ent1_y) == 0)
                // 180 deg
                event->set_point_of_contact({ent1_x - ent1_r, ent1_y});
                angle = M_PI;
            }
        } else {  // if ((ent2_x - ent1_x) == 0)
            if ((ent2_y - ent1_y) > 0) {
                // 90 deg
                event->set_point_of_contact({ent1_x, ent1_y + ent1_r});
                angle = M_PI_2;
            } else if ((ent2_y - ent1_y) < 0) {
                // 270 deg
                event->set_point_of_contact({ent1_x, ent1_y - ent1_r});
                angle = (3 * M_PI_2);
            } else {  // if ((ent2_y - ent1_y) == 0)
                // completely overlap, which is theoretically impossible...
                std::cerr << ent1->get_name() << " is in complete overlap with "
                          << ent2->get_name() << ".\n";
                assert(false);
            }
        }

        event->set_angle_of_contact((M_PI - angle) / M_PI * 180);
    }
} /* entities_have_collided() */

void Arena::CheckProximity(const Robot *sensing, const SensorProximity *sensor,
                           const ArenaEntity *sensed, EventProximity *ep) {
    bool result = false;
    double dx, dy, dist, tt, dt;
    double sensedr = sensed->get_radius(),
           sensingh = sensing->get_heading_angle(),
           sensingf = sensor->get_fov();
    Position sensingp = sensing->get_pos(), sensedp = sensed->get_pos();
    dx = sensedp.x - sensingp.x;
    dy = sensedp.y - sensingp.y;

    double sensorl, sensoru, sensedl, sensedu;

    dist = sqrt(pow(dx, 2) + pow(dy, 2));
    if (dist <= PROXIMITY_RADIUS + sensedr) {
        tt = POSITIVE(atan(sensedr / dist) * 180 / M_PI);
        dt = POSITIVE(atan2(dy, dx) * 180 / M_PI);
        sensorl = sensingh - sensingf / 2;
        sensoru = sensingh + sensingf / 2;
        sensedl = dt - tt;
        sensedu = dt + tt;
        if (Range<double>(POSITIVE(sensorl), POSITIVE(sensoru))
                .in(Range<double>(POSITIVE(sensedl), POSITIVE(sensedu))))
            result = true;
    }
    if (result) {
        ep->set_activated(true);
        ep->set_sensed(sensed);
        ep->set_distance(dist);
    } else {
        ep->set_activated(false);
    }
}

void Arena::Accept(EventKeypress *evt) {
    player_->EventCmd(evt->get_keypress());
}

void Arena::RegisterSensor(Sensor *s) { sensors_.push_back(s); }

void Arena::UnregisterSensor(Sensor *s) {
    sensors_.erase(std::remove(sensors_.begin(), sensors_.end(), s),
                   sensors_.end());
}

NAMESPACE_END(csci3081);
