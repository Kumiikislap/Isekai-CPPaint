#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/window.hpp>

using namespace godot;

class Main_Menu : public Window
{
    GDCLASS(Main_Menu, Window)

public:
    Main_Menu();
    ~Main_Menu() = default;

    void _ready() override;

    void save_settings();

protected:
    static void _bind_methods();

private:
    void set_up_tab_connections();
    void on_tab_button_pressed();
    void on_tab_pressed(StringName p_tab_button);
};
