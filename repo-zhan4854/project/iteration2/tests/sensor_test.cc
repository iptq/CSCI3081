#include "../src/sensor.h"
#include "../src/sensor_distress.h"
#include "../src/sensor_entity_type.h"
#include "../src/sensor_proximity.h"
#include <gtest/gtest.h>

class TestSensor : public csci3081::Sensor {
 public:
    ~TestSensor() {}
    void Reset() {}
};

TEST(SensorTest, Constructor) {
    TestSensor *s = new TestSensor();
    ASSERT_EQ(s->get_activated(), false);
    delete s;
}

TEST(SensorTest, SetActivated) {
    TestSensor *s = new TestSensor();
    s->set_activated(true);
    ASSERT_EQ(s->get_activated(), true);
    delete s;
}

TEST(SensorProximityTest, Constructor) {
    csci3081::SensorProximity *s = new csci3081::SensorProximity();
    ASSERT_EQ(s->get_activated(), false);
    delete s;
}

TEST(SensorDistressTest, Constructor) {
    csci3081::SensorDistress *s = new csci3081::SensorDistress();
    ASSERT_EQ(s->get_activated(), false);
    delete s;
}

TEST(SensorEntityTypeTest, Constructor) {
    csci3081::SensorEntityType *s = new csci3081::SensorEntityType();
    ASSERT_EQ(s->get_activated(), false);
    delete s;
}