#include <vector>

#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "Joucho/viewport/menu.h"
#include "util/bind.hpp"
#include "util/conversions.hpp"
#include "util/engine.hpp"

Main_Menu::Main_Menu()
{
}

void Main_Menu::_ready()
{
    // find child and connect signals
    set_up_tab_connections();
}

void Main_Menu::_bind_methods()
{
    rl::bind_member_function(Main_Menu, on_tab_button_pressed);
}

void Main_Menu::save_settings()
{
}

void Main_Menu::set_up_tab_connections()
{
    TypedArray<Button> tab_button = rl::engine::scene_tree()->get_nodes_in_group("menu_tabs_group");
    // std::vector<Node> tab_button = rl::engine::scene_tree()->get_nodes_in_group("menu_tabs_group");
    for (int i = 0; i < tab_button.size(); ++i)
    {
        Variant b = tab_button[i];

        UtilityFunctions::print(b);
    }
    Button* setting = rl::gdcast<Button>(this->find_child("Setting", true, false));
    // Button* cursor = rl::gdcast<Button>(this->find_child("Cursor", true, false));

    setting->connect("pressed", Callable(this, "on_tab_button_pressed"));
    UtilityFunctions::print(setting);

}

void Main_Menu::on_tab_button_pressed()
{
    // if (p_tab_button == "Setting")
    //{
    //	UtilityFunctions::print("a");
    // }
    UtilityFunctions::print("a");
}

void Main_Menu::on_tab_pressed(StringName p_tab_button)
{
}
