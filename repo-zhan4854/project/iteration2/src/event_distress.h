/**
 * @file event_distress.h
 *
 * @copyright 2017 Michael Zhang, All rights reserved.
 */

#ifndef SRC_EVENT_DISTRESS_H_
#define SRC_EVENT_DISTRESS_H_

#include "src/common.h"
#include "src/event_base_class.h"

NAMESPACE_BEGIN(csci3081);

class EventDistress : public EventBaseClass {
 public:
    EventDistress() : distressed_(false) {}
    EventDistress(const EventDistress &L) = delete;
    EventDistress &operator=(const EventDistress &L) {
        distressed_ = L.distressed_;
        return *this;
    }

    void EmitMessage(void) {}

    void set_distressed(bool distressed) { distressed_ = distressed; }
    bool get_distressed(void) { return distressed_; }

 private:
    bool distressed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_DISTRESS_H_
