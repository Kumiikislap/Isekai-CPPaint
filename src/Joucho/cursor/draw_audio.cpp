#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "Joucho/cursor/draw_audio.h"
#include "Joucho/util/constants.h"
#include "core/assert.hpp"
#include "util/conversions.hpp"

Drawing_Audio::Drawing_Audio()
{
}

void Drawing_Audio::_ready()
{
    gdrandom->randomize();

    draw_walk = rl::gdcast<AudioStreamPlayer>(this->find_child(nyonyo::nodes::draw_audio_walk));
    draw_complimentary = rl::gdcast<AudioStreamPlayer>(
        this->find_child(nyonyo::nodes::draw_audio_complimentary));

    runtime_assert(draw_walk != nullptr);
    runtime_assert(draw_complimentary != nullptr);

    draw_walk->play();
}

void Drawing_Audio::play_draw_audio()
{
    int audio_rng = gdrandom->randi_range(1, 2);

    // UtilityFunctions::print(audio_rng);

    if (draw_walk->is_playing() or draw_complimentary->is_playing())
        return;

    switch (audio_rng)
    {
        case 1:
        {
            draw_walk->play();
            break;
        }
        case 2:
        {
            draw_complimentary->play();
            break;
        }
    }
}

void Drawing_Audio::_bind_methods()
{
}
