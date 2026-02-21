#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "Joucho/util/constants.h"
#include "Joucho/viewport/monitor.h"
#include "util/bind.hpp"
#include "util/conversions.hpp"

Monitor::Monitor()
{
}

// dont forget to bind methods first for signal callbacks
void Monitor::_bind_methods()
{
    rl::bind_member_function(Monitor, disable_follow_mouse);
}

void Monitor::_ready()
{
    Window* window = get_window();
    window->set_flag(window->FLAG_MOUSE_PASSTHROUGH, true);  // make a polygon for menus

    godot::Node* button{ this->find_child(nyonyo::nodes::disable_follow) };
    disable_button = rl::gdcast<TextureButton>(button);

    rl::resource::preload::packed_scene<ControlMode> controlm_scene{ nyonyo::scenes::control_mode };
    m_control_mode = controlm_scene.instantiate();
    this->add_child(m_control_mode);

    // UtilityFunctions::print(disable_button);
    if (m_control_mode != nullptr)
    {
        // disable_button->connect("pressed" , Callable(this, "disable_follow_mouse"));
        rl::signal<nyonyo::events::disable_follow_event>::connect<TextureButton>(disable_button) <=>
            signal_callback(this, disable_follow_mouse);
    }
}

void Monitor::_process(double p_delta)
{
    // process polygon passthrough
}

void Monitor::disable_follow_mouse(const bool p_state)
{
    if (p_state)
        m_control_mode->set_mode(ControlMode::MODE::GOMIDASU);
    else
        m_control_mode->set_mode(ControlMode::MODE::CURSOR_FOLLOW);

    // UtilityFunctions::print(p_state);
}
