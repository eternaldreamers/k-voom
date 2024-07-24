#ifndef PARTICULAS_H
#define PARTICULAS_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/array.hpp>

using namespace godot;

class Particulas : public RefCounted {
    GDCLASS(Particulas, RefCounted);

protected:
    static void _bind_methods();

public:
    Array particle_positions;  // Usando Array en lugar de std::vector
    Array particle_velocities;

    Particulas();
    ~Particulas();

    void step(int iterations);
    void explode(Vector2 center, int num_particles);
    Array get_positions() const;
};

#endif
