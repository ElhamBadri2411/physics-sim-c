#include "particle_system.h"
#include "particle.h"
#include <stdio.h>
#include <stdlib.h>

void init_particle_system(ParticleSystem *system, int capacity) {
  system->particles = malloc(sizeof(Particle) * capacity);
  system->size = 0;
  system->capacity = capacity;
}

void update(ParticleSystem *system, float dt) {
  for (int i = 0; i < system->size; i++) {
    update_particle(&system->particles[i], dt);
  }
}

void add_particle(ParticleSystem *system, Particle new_particle) {
  // handle expanding array case
  if (system->size == system->capacity) {
    int new_capacity = system->capacity * 2;
    Particle *new_array =
        realloc(system->particles, new_capacity * sizeof(Particle));
    if (new_array == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
    system->particles = new_array;
    system->capacity = new_capacity;
  }

  // Add the new particle
  system->particles[system->size] = new_particle;
  system->size++;
}
