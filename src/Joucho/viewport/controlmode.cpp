#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "Joucho/viewport/controlmode.h"
#include "util/bind.hpp"

ControlMode::ControlMode()
{
    // instatiate and add child cursor
}

void ControlMode::_bind_methods()
{
    [[property]] rl::bind_property(ControlMode, offset, Vector2);
}

void ControlMode::_ready()
{
    rl::resource::preload::packed_scene<nyo::Cursor> cursor_scene{ nyonyo::scenes::cursor_test };
    current_cursor = cursor_scene.instantiate();
    rl::resource::preload::packed_scene<Drawing_Audio> audio_scene{ nyonyo::scenes::drawing_audio };
    drawing_audio = audio_scene.instantiate();

    this->add_child(drawing_audio);

    if (current_cursor != nullptr)
    {
        this->add_child(current_cursor);
        UtilityFunctions::print(current_cursor);
    }
}

void ControlMode::_process(double p_delta)
{
    DisplayServer* DSingle = DisplayServer::get_singleton();
    this->current_mouse_state = DSingle->mouse_get_button_state();

    if (current_mode == MODE::CURSOR_FOLLOW)
    {
        Vector2 mouse_pos = get_global_mouse_position();
        current_cursor->set_position(mouse_pos - offset);

        if (!current_cursor->is_visible())
            current_cursor->show();

        process_animations();
    }
    if (current_mode == MODE::GOMIDASU)
        current_cursor->hide();
    // control cursor
}

// funcs to change modes by button or by setter

void ControlMode::process_animations()
{
    if (current_mouse_state == BUTTON_STATE::HOVER)
        current_cursor->play("idle");
    if (current_mouse_state == BUTTON_STATE::LEFT_BUTTON)
    {
        current_cursor->play("drawing");
        drawing_audio->play_draw_audio();
    }
    if (current_mouse_state == BUTTON_STATE::RIGHT_BUTTON)
        current_cursor->play("singing");
}

void ControlMode::set_mode(const ControlMode::MODE p_mode)
{
    this->current_mode = p_mode;
}

ControlMode::MODE ControlMode::get_mode() const
{
    return current_mode;
}

void ControlMode::set_offset(const Vector2 p_offset)
{
    this->offset = p_offset;
}

Vector2 ControlMode::get_offset() const
{
    return offset;
}
