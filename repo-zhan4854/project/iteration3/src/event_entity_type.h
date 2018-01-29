/**
 * @file event_entity_type.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_EVENT_ENTITY_TYPE_H_
#define SRC_EVENT_ENTITY_TYPE_H_

#include "src/entity_type.h"
#include "src/event_base_class.h"

NAMESPACE_BEGIN(csci3081);

class EventEntityType : public EventBaseClass {
 public:
    explicit EventEntityType(enum entity_type entity_type)
        : activated_(false), entity_type_(entity_type) {}
    void EmitMessage(void) {}

    bool get_activated() const { return activated_; }
    void set_activated(bool value) { activated_ = value; }

    enum entity_type get_entity_type() const { return entity_type_; }
    void set_entity_type(enum entity_type value) { entity_type_ = value; }

 private:
    bool activated_;
    enum entity_type entity_type_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_ENTITY_TYPE_H_
