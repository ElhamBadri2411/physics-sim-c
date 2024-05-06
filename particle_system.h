#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "particle.h"

typedef struct particly_dynamic_array {
  Particle *particles;
  int size;
  int capacity;
} ParticleSystem;

void init_particle_system(ParticleSystem *system, int capacity);
void add_particle(ParticleSystem *system, Particle new_particle);
void update(ParticleSystem *system, float dt);

#endif // !PARTICLE_SYSTEM_H
