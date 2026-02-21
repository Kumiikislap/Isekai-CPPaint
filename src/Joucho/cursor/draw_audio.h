#include <godot_cpp/classes/audio_stream_player.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>

using namespace godot;

class Drawing_Audio : public Node2D
{
    GDCLASS(Drawing_Audio, Node2D)

public:
    Drawing_Audio();
    ~Drawing_Audio() = default;

    bool drawing_mode{ false };

    void _ready() override;
    void play_draw_audio();

protected:
    static void _bind_methods();

private:
    bool is_currently_playing{ false };

    Ref<RandomNumberGenerator> gdrandom{ memnew(RandomNumberGenerator) };
    AudioStreamPlayer* draw_walk{ nullptr };
    AudioStreamPlayer* draw_complimentary{ nullptr };
};
