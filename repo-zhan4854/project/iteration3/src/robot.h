/**
 * @file robot.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <string>

#include "src/arena_mobile_entity.h"
#include "src/common.h"
#include "src/entity_type.h"
#include "src/motion_behavior_robot.h"
#include "src/motion_handler_robot.h"
#include "src/robot_params.h"
#include "src/sensor_distress.h"
#include "src/sensor_entity_type.h"
#include "src/sensor_proximity.h"
#include "src/sensor_touch.h"

NAMESPACE_BEGIN(csci3081);

class Robot : public ArenaMobileEntity {
 public:
    explicit Robot(const struct robot_params *const params);
    void Reset(void);
    void TimestepUpdate(double dt);

    void Accept(EventRecharge *evt);
    void Accept(EventCollision *evt);

    void set_entity_type(enum entity_type entity_type) {
        entity_type_ = entity_type;
    }
    enum entity_type get_entity_type() const { return entity_type_; }
    std::string get_name() const { return "Robot " + std::to_string(get_id()); }

    int get_id(void) const { return id_; }

    double get_heading_angle(void) const {
        return motion_handler_.get_heading_angle();
    }
    void set_heading_angle(double ha) { motion_handler_.set_heading_angle(ha); }
    double get_speed(void) { return motion_handler_.get_speed(); }
    void set_speed(double sp) { motion_handler_.set_speed(sp); }

    SensorProximity *get_sensor_proximity_left(void) {
        return sensor_proximity_left_;
    }
    SensorProximity *get_sensor_proximity_right(void) {
        return sensor_proximity_right_;
    }
    SensorDistress *get_sensor_distress(void) { return &sensor_distress_; }
    SensorEntityType *get_sensor_entity_type(void) {
        return &sensor_entity_type_;
    }

    double get_initial_speed() { return motion_handler_.get_initial_speed(); }
    void upgrade(void);

 private:
    const robot_params initial_params_;
    static unsigned int next_id_;
    int id_;
    enum entity_type entity_type_;

    MotionBehaviorRobot motion_behavior_;
    MotionHandlerRobot motion_handler_;

    SensorProximity *sensor_proximity_left_, *sensor_proximity_right_;
    SensorDistress sensor_distress_;
    SensorEntityType sensor_entity_type_;

    //! @brief Assignment operator. Satisfies compilers warning that the
    //! assignment operator should not exist.
    Robot &operator=(const Robot &other) = delete;

    //! @brief Copy constructor. Satisfies compilers warning that the copy
    //! constructor should not exist.
    Robot(const Robot &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_H_
