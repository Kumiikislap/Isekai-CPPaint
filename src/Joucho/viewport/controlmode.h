#pragma once

#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/node2d.hpp>

#include "Joucho/cursor/cursor.h"
#include "Joucho/cursor/draw_audio.h"
#include "Joucho/util/constants.h"
#include "util/scene.hpp"

using namespace godot;

class ControlMode : public Node2D
{
    GDCLASS(ControlMode, Node2D)

public:
    enum class MODE {
        CURSOR_FOLLOW,
        WONDERING,
        GOMIDASU,
    };

private:
    enum BUTTON_STATE {
        HOVER,
        LEFT_BUTTON,
        RIGHT_BUTTON,
    };

    BitField<MouseButtonMask> current_mouse_state{ 0 };
    [[property]] Vector2 offset{ -70, -70 };

    Drawing_Audio* drawing_audio{ nullptr };
    nyo::Cursor* current_cursor{ nullptr };

protected:
    void process_animations();

public:
    ControlMode();
    ~ControlMode() = default;

    static void _bind_methods();
    void _ready() override;
    void _process(double delta) override;

    [[property]] void set_mode(const ControlMode::MODE p_mode);
    [[property]] void set_offset(const Vector2 p_offset);

    [[property]] ControlMode::MODE get_mode() const;
    [[property]] Vector2 get_offset() const;

    MODE current_mode{ MODE::CURSOR_FOLLOW };
};
