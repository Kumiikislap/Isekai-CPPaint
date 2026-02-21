#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/classes/window.hpp>

#include "Joucho/JouMain.h"

JouMain::JouMain()
{
    // rl::resource::preload::packed_scene<Monitor> monitor{ nyonyo::scenes::Monitor };

    // current_monitor = monitor.instantiate();
    // if (current_monitor != nullptr)
    //     this->add_child(current_monitor);
}

void JouMain::_bind_methods()
{
}

void JouMain::_ready()
{
    this->initialize_window();
}

void JouMain::initialize_window()
{
    Window* window = get_window();
    DisplayServer* DSingle = DisplayServer::get_singleton();

    window->set_size(DSingle->screen_get_size());
    window->set_position(DSingle->screen_get_position());
    window->set_mode(window->MODE_FULLSCREEN);
    // window->set_flag(window->FLAG_MOUSE_PASSTHROUGH, true); // make a polygon for menus
}

