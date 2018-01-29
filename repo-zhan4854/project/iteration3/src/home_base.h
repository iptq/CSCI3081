/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

#include <string>

#include "src/arena_mobile_entity.h"
#include "src/entity_type.h"
#include "src/event_collision.h"
#include "src/event_recharge.h"
#include "src/home_base_params.h"
#include "src/sensor_touch.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The home base that Robots are trying to collide with to turn into
 * SuperBots.
 */
class HomeBase : public ArenaMobileEntity {
 public:
    //! @brief Default constructor.
    explicit HomeBase(const struct home_base_params *const params);

    //! @brief An update function that is called every frame of the simulation.
    void TimestepUpdate(double dt);
    void Reset(void);

    enum entity_type get_entity_type(void) const {
        return entity_type::kHomeBase;
    }
    std::string get_name(void) const { return "Home Base"; }

    double get_heading_angle(void) const { return heading_angle_; }
    void set_heading_angle(double ha) { heading_angle_ = ha; }
    double get_speed(void) { return speed_; }
    void set_speed(double sp) { speed_ = sp; }
    void Accept(EventCollision *evt);
    void Accept(EventRecharge *evt);

 private:
    //! @brief The current heading angle of the home base.
    double heading_angle_;

    //! @brief The current speed of the home base.
    double speed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_HOME_BASE_H_
