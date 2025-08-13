#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "cursor.h"
#include "core/constants.hpp"
#include "singletons/SGlobal.h"

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
	
//        SGlobal& singleton = SGlobal::get_instance();
//		
//		singleton.data = 39;
//		singleton.vec2 = {100,100};
//
//		set_position(singleton.vec2);
        godot::UtilityFunctions::print(rl::name::character::player);
    }

    void Cursor::_process(double p_delta)
    {
        //mousepos = get_global_mouse_position();

        //set_position(mousepos - offset);
    }

    Cursor::~Cursor()
    {
    }
}
