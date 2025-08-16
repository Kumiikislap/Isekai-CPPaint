#pragma once

#include <godot_cpp/classes/animated_sprite2d.hpp>

namespace nyo
{
    class Cursor : public godot::AnimatedSprite2D
    {
        GDCLASS(Cursor, AnimatedSprite2D);

    protected:
        static void _bind_methods();

        godot::Vector2i offset = { -70, -70 };
        godot::Vector2i mousepos = { 0, 0 };

    public:
        virtual void _process(double p_delta) override;
        void _ready() override;

        Cursor();
        ~Cursor() = default;
    };
}
