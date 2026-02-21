#pragma once

#include <godot_cpp/classes/control.hpp>

#include "Joucho/viewport/monitor.h"

using namespace godot;

class JouMain : public Control
{
    GDCLASS(JouMain, Control);

public:
    JouMain();
    ~JouMain() = default;

    static void _bind_methods();

    void _ready() override;

protected:
    void initialize_window();

private:
    Monitor* current_monitor{ nullptr };
};
