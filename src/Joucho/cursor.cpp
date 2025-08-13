#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "cursor.h"

namespace nyo 
{
    Cursor::Cursor()
    {
    }

    void Cursor::_bind_methods()
    {
    }

    void Cursor::_ready()
    {
    }

    void Cursor::_process(double p_delta)
    {
        mousepos = get_global_mouse_position();

        set_position(mousepos - offset);
    }

    Cursor::~Cursor()
    {
    }
}
