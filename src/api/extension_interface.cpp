#include <type_traits>

#include <gdextension_interface.h>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/string_name.hpp>

#include "Joucho/JouMain.h"
#include "Joucho/cursor/cursor.h"
#include "Joucho/viewport/controlmode.h"
#include "Joucho/viewport/menu.h"
#include "Joucho/viewport/monitor.h"
#include "api/extension_interface.hpp"
#include "entity/camera.hpp"
#include "entity/character/character.hpp"
#include "entity/character/enemy.hpp"
#include "entity/character/player.hpp"
#include "entity/controller/character_controller.hpp"
#include "entity/controller/enemy_controller.hpp"
#include "entity/controller/player_controller.hpp"
#include "entity/level.hpp"
#include "entity/projectile/projectile_spawner.hpp"
#include "main.hpp"
#include "singletons/console.hpp"
#include "singletons/sglobal.h"
#include "ui/main_dialog.hpp"
#include "util/engine.hpp"

namespace rl
{
    static inline console* console_singleton{ nullptr };
    static inline SGlobal* global_singleton{ nullptr };

    void initialize_static_objects()
    {
        console_singleton = memnew(console);
        rl::engine::get()->register_singleton("Console", console::get());

        global_singleton = memnew(SGlobal);
        rl::engine::get()->register_singleton("SGlobal", SGlobal::get_ins());
    }

    void teardown_static_objects()
    {
        rl::engine::get()->unregister_singleton("Console");
        memdelete(console_singleton);

        rl::engine::get()->unregister_singleton("SGlobal");
        memdelete(global_singleton);
    }

    void initialize_extension_module(godot::ModuleInitializationLevel init_level)
    {
        if (init_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE)
            return;

        godot::ClassDB::register_class<rl::Projectile>();
        godot::ClassDB::register_class<rl::ProjectileSpawner>();

        godot::ClassDB::register_abstract_class<rl::CharacterController>();
        godot::ClassDB::register_class<rl::PlayerController>(true);
        godot::ClassDB::register_class<rl::EnemyController>();

        godot::ClassDB::register_class<rl::Camera>();
        godot::ClassDB::register_class<rl::Character>();
        godot::ClassDB::register_class<rl::Enemy>();
        godot::ClassDB::register_class<rl::Player>();

        godot::ClassDB::register_class<rl::Level>();
        godot::ClassDB::register_class<rl::MainDialog>();
        godot::ClassDB::register_class<rl::Main>();

        godot::ClassDB::register_class<console>();
        godot::ClassDB::register_class<SGlobal>();

        godot::ClassDB::register_runtime_class<Drawing_Audio>();
        godot::ClassDB::register_runtime_class<nyo::Cursor>();
        godot::ClassDB::register_runtime_class<ControlMode>();
        godot::ClassDB::register_runtime_class<Monitor>();
        godot::ClassDB::register_runtime_class<JouMain>();

        godot::ClassDB::register_runtime_class<Main_Menu>();

        initialize_static_objects();
    }

    void uninitialize_extension_module(godot::ModuleInitializationLevel init_level)
    {
        if (init_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE)
            return;

        teardown_static_objects();
    }

    extern "C"
    {
        GDExtensionBool GDE_EXPORT extension_library_init(GDExtensionInterfaceGetProcAddress addr,
                                                          GDExtensionClassLibraryPtr lib,
                                                          GDExtensionInitialization* init)
        {
            const auto init_level = godot::MODULE_INITIALIZATION_LEVEL_SCENE;
            godot::GDExtensionBinding::InitObject init_obj(addr, lib, init);

            init_obj.register_initializer(initialize_extension_module);
            init_obj.register_terminator(uninitialize_extension_module);
            init_obj.set_minimum_library_initialization_level(init_level);

            return init_obj.init();
        }
    }
}
