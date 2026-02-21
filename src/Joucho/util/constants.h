#pragma once

namespace nyonyo::inline constants
{
    namespace test
    {
        constexpr inline auto test1{ "test1" };
    }

    namespace nodes
    {
        constexpr inline auto disable_follow{ "Toggle_Hover" };

        constexpr inline auto draw_audio_walk{ "draw_walk" };
        constexpr inline auto draw_audio_complimentary{ "draw_complimentary" };
    }

    namespace events
    {
        constexpr inline auto disable_follow_event{ "toggled" };
    }

    namespace scenes
    {
        constexpr inline auto cursor_test{ "res://joucho/cursor/cursor.tscn" };
        constexpr inline auto control_mode{ "res://joucho/viewport/control_mode.tscn" };
        constexpr inline auto Monitor{ "res://joucho/viewport/monitor.tscn" };

        constexpr inline auto drawing_audio{ "res://joucho/cursor/drawing_audio.tscn" };
    }
}
