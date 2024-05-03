
#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector.h"

typedef struct particle_2d {
  vec2 position;
  vec2 velocity;
  vec2 acceleration;
  float mass;
} Particle;

void init_particle(Particle *p, vec2 position, vec2 velocity, float mass);
void update_particle(Particle *p, float delta_time);
void apply_force(Particle *p, vec2 force);
void reset_particle(Particle *p);

#endif // !PARTICLE_H
