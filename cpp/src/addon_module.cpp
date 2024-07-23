#include "addon_module.hpp"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

AddonModule::AddonModule() {
    _time_passed = 0.9;
}

AddonModule::~AddonModule() { }

void AddonModule::_bind_methods() { }

void AddonModule::_process(double delta) {
    _time_passed += delta;

    Vector2 new_position = Vector2(10.0 + (10.0 * sin(_time_passed * 2.0)), 10.0 + (10.0 * cos(_time_passed * 1.5)));

    set_position(new_position);
}