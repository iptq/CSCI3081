/**
 * @file recharge_station.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_RECHARGE_STATION_H_
#define SRC_RECHARGE_STATION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/color.h"
#include "src/entity_type.h"
#include "src/obstacle.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class RechargeStation : public Obstacle {
 public:
    RechargeStation(double radius, const Position &pos,
                    const csci3081::Color &color)
        : Obstacle(radius, pos, color) {}
    enum entity_type get_entity_type(void) const {
        return entity_type::kRechargeStation;
    }
    std::string get_name(void) const { return "Recharge Station"; }
};

NAMESPACE_END(csci3081);

#endif  // SRC_RECHARGE_STATION_H_
