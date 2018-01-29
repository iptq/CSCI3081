/**
 * @file obstacle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/arena_immobile_entity.h"
#include "src/color.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Obstacle : public ArenaImmobileEntity {
 public:
    Obstacle(double radius, const Position &pos, const csci3081::Color &color);

    enum entity_type get_entity_type(void) const {
        return entity_type::kObstacle;
    }
    std::string get_name(void) const {
        return "Obstacle" + std::to_string(id_);
    }

 private:
    static uint next_id_;

    int id_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSTACLE_H_
