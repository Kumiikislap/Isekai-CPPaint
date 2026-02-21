#pragma once

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/texture_button.hpp>

#include "Joucho/viewport/controlmode.h"

using namespace godot;

class Monitor : public Control
{
    GDCLASS(Monitor, Control);

public:
    Monitor();
    ~Monitor() = default;

    [[signal_slot]] void disable_follow_mouse(const bool p_state);

    void _ready() override;
    void _process(double p_delta) override;

protected:
    static void _bind_methods();

private:
    TextureButton* disable_button{ nullptr };
    ControlMode* m_control_mode{ nullptr };
};
