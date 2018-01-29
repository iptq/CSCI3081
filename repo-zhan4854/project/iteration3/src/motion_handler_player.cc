/**
 * @file motion_handler_player.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_player.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionHandlerPlayer::AcceptCommand(enum event_commands cmd) {
    int nspeed, mspeed;
    switch (cmd) {
    case COM_SPEED_UP:
        nspeed = get_speed() + 10;
        if (nspeed > (mspeed = get_max_speed()))
            nspeed = mspeed;
        set_speed(nspeed);
        break;
    case COM_SLOW_DOWN:
        nspeed = get_speed() - 10;
        if (nspeed < 0)
            nspeed = 0;
        set_speed(nspeed);
        break;
    case COM_TURN_LEFT:
        set_heading_angle(get_heading_angle() - get_angle_delta());
        break;
    case COM_TURN_RIGHT:
        set_heading_angle(get_heading_angle() + get_angle_delta());
        break;
    case COM_UNKNOWN:
        break;
    default:
        std::cerr << "FATAL: bad actuator command" << std::endl;
        assert(0);
    } /* switch() */
} /* accept_command() */

void MotionHandlerPlayer::UpdateVelocity(SensorTouch *st) {
    if (st->get_activated()) {
        set_heading_angle(-st->get_angle_of_contact());
        st->set_activated(false);
    }
}

void MotionHandlerPlayer::Accept(EventCollision *ec) {
    int nspeed;
    if (ec->get_collided()) {
        nspeed = get_speed() - 3;
        if (nspeed < 0)
            nspeed = 0;
        set_speed(nspeed);
    }
}

NAMESPACE_END(csci3081);
