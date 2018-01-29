/**
 * @file player_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player_battery.h"
#include <cmath>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double PlayerBattery::Deplete(__unused Position old_pos,
                              __unused Position new_pos, __unused double dt) {
    /* @todo deplete battery by some value based on movement and speed */
    double dp =
        sqrtf(powf(new_pos.x - old_pos.x, 2) + powf(new_pos.y - old_pos.y, 2));
    double amount = (kBASE_DEPLETION + kLINEAR_SCALE_FACTOR * dp) * dt;
    this->charge_ -= amount;
    if (this->charge_ < 0)
        this->charge_ = 0;
    return charge_;
} /* deplete() */

void PlayerBattery::Accept(__unused EventCollision *e) {
    if (e->get_collided()) {
        this->charge_ -= 10;
    }
}

NAMESPACE_END(csci3081);
