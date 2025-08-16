#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "Joucho/util/constants.h"
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
        godot::UtilityFunctions::print(nyonyo::test::test1);
    }

    void Cursor::_process(double p_delta)
    {
        mousepos = get_global_mouse_position();

        set_position(mousepos - offset);
		
		godot::DisplayServer& DSingle = *godot::DisplayServer::get_singleton();

		godot::BitField<godot::MouseButtonMask> miao  = DSingle.mouse_get_button_state();

        godot::UtilityFunctions::print(miao);
	
    }
}
