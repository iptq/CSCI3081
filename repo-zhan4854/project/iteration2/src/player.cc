/**
 * @file player.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player.h"
#include "src/event_command.h"
#include "src/motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Player::Player(const struct player_params *const params)
    : ArenaMobileEntity(params->radius, params->collision_delta, params->pos,
                        params->color),
      battery_(params->battery_max_charge), motion_handler_(),
      motion_behavior_() {
    motion_handler_.set_heading_angle(270),
        motion_handler_.set_angle_delta(params->angle_delta);
    motion_handler_.set_initial_speed(50);
    set_pos(params->pos);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Player::TimestepUpdate(double dt) {
    if (get_frozen()) {
        dec_fcountdown(dt);
    }

    Position old_pos = get_pos();
    // Update heading and speed as indicated by touch sensor
    motion_handler_.UpdateVelocity(get_sensor_touch());
    // Use velocity and position to update position
    motion_behavior_.UpdatePosition(this, dt);
    // Deplete battery as appropriate given distance and speed of movement
    battery_.Deplete(old_pos, get_pos(), dt);
    // Also deplete the battery if the sensor was activated
} /* TimestepUpdate() */

void Player::Accept(__unused EventRecharge *e) { battery_.EventRecharge(); }

// Pass along a collision event (from arena) to the touch sensor. This method
// provides a framework in which sensors can get different types of information
// from different sources.
void Player::Accept(EventCollision *e) {
    get_sensor_touch()->Accept(e);
    // also deplete the battery
    battery_.Accept(e);
    // also slow down the player
    motion_handler_.Accept(e);
}

// User input commands to change heading or speed
void Player::EventCmd(EventCommand cmd) {
    if (!get_frozen())
        motion_handler_.AcceptCommand(cmd.get_cmd());
} /* event_cmd() */

void Player::Reset(void) {
    set_pos(get_initial());
    battery_.Reset();
    motion_handler_.Reset();
    get_sensor_touch()->Reset();
} /* Reset() */

void Player::ResetBattery(void) { battery_.Reset(); }

NAMESPACE_END(csci3081);
