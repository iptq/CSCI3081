/**
 * @file graphics_arena_viewer.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_GRAPHICS_ARENA_VIEWER_H_
#define SRC_GRAPHICS_ARENA_VIEWER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <simple_graphics/graphics_app.h>
#include <sys/time.h>

#include "src/arena.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 *  @brief An application that uses the cs3081 SimpleGraphics library to open up
 *  a window that includes a few buttons for controlling the simulation and can
 *  be used to draw circles and other computer graphics.
 *
 *  After constructing a new RobotViewer, call Run() to start and run the
 *  application.  Run() will not return until the application window is closed.
 *  Make sure that you call cs3081::InitGraphics() before creating the
 *  RobotViewer app.  Example:
 *
 *  ```
 *  int main(int argc, char **argv) {
 *      cs3081::InitGraphics();
 *      RobotViewer *app = new RobotViewer();
 *      app->Run();
 *      cs3081::ShutdownGraphics();
 *      return 0;
 *  }
 *  ```
 *
 *  While the window is open \ref UpdateSimulation() will be called repeatedly,
 *  once per frame.  Fill this in to update your simulation or perform any other
 *  processing that should happen over time as the simulation progresses.
 *
 *  Fill in the On*() methods as desired to respond to user input events.
 *
 *  Fill in the Draw*() methods to draw graphics to the screen using
 *  either the nanovg library or raw OpenGL.
 */
class GraphicsArenaViewer : public GraphicsApp {
 public:
    /**
     * @brief Constructor. Creates a new GraphicsArenaViewer with the given
     * parameters.
     *
     * @param params The parameters used to initialize members.
     */
    explicit GraphicsArenaViewer(const struct arena_params *const params);

    /**
     * @brief Destructor.
     *
     * Deletes the pointer members of this class.
     */
    virtual ~GraphicsArenaViewer(void) {
        delete arena_;
        delete pause_btn_;
    }

    /**
     * @brief Informs the arena of the new time, so that it can update.
     */
    void UpdateSimulation(double dt);

    /**
     * @brief Handle the user pressing the restart button on the GUI.
     */
    void OnRestartBtnPressed();

    /**
     * @brief Handle the user pressing the pause button on the GUI.
     */
    void OnPauseBtnPressed();

    /**
     * @brief Called each time the mouse moves on the screen within the GUI
     * window.
     *
     * Origin is at the lower left of the window.
     *
     * @param[in] x X position of the cursor.
     * @param[in] y Y position of the cursor.
     */
    void OnMouseMove(int x, int y);

    /**
     * @brief Called each time the left mouse button is clicked.
     *
     * Origin is at the lower left of the window.
     *
     * @param[in] x The X position of the click.
     * @param[in] y The Y position of the click.
     */
    void OnLeftMouseDown(int x, int y);

    /**
     * @brief Called each time the left mouse button is released.
     *
     * Origin is at the lower left of the window.
     *
     * @param[in] x The X position of the release.
     * @param[in] y The Y position of the release.
     */
    void OnLeftMouseUp(int x, int y);

    /**
     * @brief Called each time the right mouse button is clicked.
     *
     * Origin is at the lower left of the window.
     *
     * @param[in] x The X position of the click.
     * @param[in] y The Y position of the click.
     */

    void OnRightMouseDown(int x, int y);

    /**
     * @brief Called each time the right mouse button is released.
     *
     * Origin is at the lower left of the window.
     *
     * @param[in] x The X position of the release.
     * @param[in] y The Y position of the release.
     */
    void OnRightMouseUp(int x, int y);

    /**
     * @brief Called each time a character key is pressed.
     *
     * @param[in] c Character representing a key that was pressed.
     * @param[in] modifiers Any modifier keys that were also pressed.
     */
    void OnKeyDown(const char *c, int modifiers);

    /**
     * @brief Called each time a character key is released.
     *
     * @param[in] c Character representing a key that was released.
     * @param[in] modifiers Any modifier keys that were held with the key.
     */
    void OnKeyUp(const char *c, int modifiers);

    /**
     * @brief Called each time a special (non-alphabetic) key is pressed.
     *
     * @param[in] key The key that was pressed.
     * @param[in] scancode The scancode corresponding to the key.
     * @param[in] modifiers Any modifiers that were also pressed.
     */
    void OnSpecialKeyDown(int key, int scancode, int modifiers);

    /**
     * @brief Called each time a special (non-alphabetic) key is released.
     *
     * @param[in] key The key that was released.
     * @param[in] scancode The scancode corresponding to the key.
     * @param[in] modifiers Any modifiers that were also pressed.
     */
    void OnSpecialKeyUp(int key, int scancode, int modifiers);

    /**
     * @brief Draw the arena with all robots, obstacles using nanogui.
     *
     * @param[in] ctx Context for nanogui.
     */
    void DrawUsingNanoVG(NVGcontext *ctx);

    /**
     * @brief Draw using OpenGL. This callback had to be defined, but we are
     * doing
     * all drawing with nanovg in this application, so it is empty.
     */
    void DrawUsingOpenGL(void) {}

    void draw(NVGcontext *ctx) override {
        double now = glfwGetTime();
        UpdateSimulation(now - last_draw_time_);
        last_draw_time_ = now;

        // Draw other vector graphics using the nanovg library
        DrawUsingNanoVG(ctx);

        // Draw the user interface using the nanogui library, which is built
        // upon nanovg
        Screen::draw(ctx);
    }

    Arena *get_arena(void) const { return arena_; }

 private:
    /**
     * @brief Draw a circular entity using nanogui.
     */
    void DrawCircularEntity(NVGcontext *ctx,
                            const class ArenaMobileEntity *const entity);

    /**
     * @brief Draw the player using nanogui.
     *
     * This function requires an active nanovg drawing context (ctx), so it
     * should probably only be called from with \ref DrawUsingNanoVG().
     *
     * @param[in] ctx The nanogui context.
     * @param[in] player The player handle.
     */
    void DrawPlayer(NVGcontext *ctx, const class Player *const player);

    /**
     * @brief Draw the robot using nanogui.
     */
    void DrawRobot(NVGcontext *ctx, const class Robot *const robot);

    /**
     * @brief Draw an obstacle in the arena using nanogui.
     *
     * This function requires an active nanovg drawing context (ctx), so it
     * should probably only be called from with \ref DrawUsingNanoVG().
     *
     * @param[in] ctx The nanogui context.
     * @param[in] obstacle The obstacle handle.
     */
    void DrawObstacle(NVGcontext *ctx, const class Obstacle *const obstacle);

    /**
     * @brief Draw the home base in the arena using nanogui.
     *
     * @param[in] ctx The nanogui context.
     * @param[in] home The home base.
     */
    void DrawHomeBase(NVGcontext *ctx, const class HomeBase *const home);

    //! @brief A reference to an arena object on the heap.
    Arena *arena_;

    //! @brief A reference to the pause button, used for changing its text.
    nanogui::Button *pause_btn_;

    //! @brief Flag indicating whether the dialog box is being shown.
    bool show_dialog_;

    /**
     * @brief The last time the simulation has been updated.
     *
     * This is used to calculate the delta time used for updating the arena and
     * its entities on a more real-time level, rather than updating by 1 time
     * step per update.
     */
    double last_draw_time_;

    //! @brief Assignment operator. Satisfies compilers warning that the
    //! assignment operator should not exist.
    GraphicsArenaViewer &operator=(const GraphicsArenaViewer &other) = delete;

    //! @brief Copy constructor. Satisfies compilers warning that the copy
    //! constructor should not exist.
    GraphicsArenaViewer(const GraphicsArenaViewer &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_GRAPHICS_ARENA_VIEWER_H_
