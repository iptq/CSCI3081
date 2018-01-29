/**
 * @file arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_H_
#define SRC_ARENA_ENTITY_H_

#include <nanogui/nanogui.h>
#include <string>

#include "src/color.h"
#include "src/common.h"
#include "src/entity_type.h"
#include "src/position.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief A base class representing an entity within the arena. All entities
 * within the arena know how to :
 *
 * 1. Update themselves each timestep (i.e. in accordance with current velocity
 *    and position).
 * 2. Reset themselves to a newly constructed state. This is so the user can
 *    click the reset button after completing a game and have things work as
 *    expected.
 *
 * Note that not all classes need to be able to do these two things.
 */
class ArenaEntity {
 public:
    /**
     * @brief Constructor. Creates an ArenaEntity out of the specified
     * parameters.
     *
     * @param radius The radius of the entity.
     * @param pos A Position object representing the coordinates at which this
     * entity starts.
     * @param @color The color of the entity.
     */
    ArenaEntity(double radius, const Position &pos,
                const csci3081::Color &color)
        : radius_(radius), pos_(pos), color_(color) {}

    /**
     * @brief Destructor. Destroys the current ArenaEntity.
     *
     * Since this class has no pointer members yet, this destructor doesn't do
     * anything.
     */
    virtual ~ArenaEntity(void) {}

    /**
     * @brief Overrided by child classes to perform whatever updates are needed
     * for a particular entity after a period of dt time.
     */
    virtual void TimestepUpdate(__unused double dt) {}

    //! @brief Reset the entity to its newly constructed state.
    virtual void Reset(void) {}

    //! @brief Gets the name of the current entity.
    virtual std::string get_name(void) const = 0;

    //! @brief Gets the entity type.
    virtual enum entity_type get_entity_type(void) const = 0;

    //! @brief Gets the position of the current entity.
    Position get_pos() const { return pos_; }

    //! @brief Sets the position of the current entity to pos.
    void set_pos(Position pos) { pos_ = pos; }

    //! @brief Gets the color of the current entity.
    const csci3081::Color &get_color(void) const { return color_; }

    //! @brief Sets the color of the current entity to color.
    void set_color(const csci3081::Color &color) { color_ = color; }

    //! @brief Gets whether the entity is a mobile entity.
    virtual bool is_mobile(void) = 0;

    //! @brief Gets the radius of the current entity.
    double get_radius(void) const { return radius_; }

 private:
    //! @brief The radius of the entity.
    double radius_;

    //! @brief The current position of the entity.
    Position pos_;

    //! @brief The color of the entity.
    csci3081::Color color_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_ENTITY_H_
