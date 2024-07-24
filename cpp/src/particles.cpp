#include "particles.hpp"
#include <godot_cpp/variant/utility_functions.hpp>
#include <cmath>

using namespace godot;

Particulas::Particulas() {
    particle_positions = Array();
    particle_velocities = Array();
}

Particulas::~Particulas() {}

void Particulas::explode(Vector2 center, int num_particles) {
    particle_positions.clear();
    particle_velocities.clear();

    for (int i = 0; i < num_particles; ++i) {
        float angle = static_cast<float>(rand()) / RAND_MAX * Math_PI * 2.0f;
        float speed = static_cast<float>(rand()) / RAND_MAX * 5.0f;

        Vector2 velocity = Vector2(cos(angle), sin(angle)) * speed;
        particle_positions.append(center);
        particle_velocities.append(velocity);
    }
}

void Particulas::step(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        for (int j = 0; j < particle_positions.size(); ++j) {
            Vector2 pos = particle_positions[j];
            Vector2 vel = particle_velocities[j];
            pos += vel;
            vel *= 0.95;  // Simulate friction
            particle_positions[j] = pos;
            particle_velocities[j] = vel;
        }
    }
}

Array Particulas::get_positions() const {
    return particle_positions;
}

void Particulas::_bind_methods() {
    ClassDB::bind_method(D_METHOD("step", "iterations"), &Particulas::step);
    ClassDB::bind_method(D_METHOD("explode", "center", "num_particles"), &Particulas::explode);
    ClassDB::bind_method(D_METHOD("get_positions"), &Particulas::get_positions);
}
