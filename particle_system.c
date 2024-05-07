#include "particle_system.h"
#include "particle.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void init_particle_system(ParticleSystem *system, int capacity) {
  system->particles = malloc(sizeof(Particle) * capacity);
  system->size = 0;
  system->capacity = capacity;
}

void resolve_collision(Particle *p1, Particle *p2) {
  // TODO
}

void update(ParticleSystem *system, float dt) {

  // check collisions between all particles
  for (int i = 0; i < system->size - 1; i++) {
    for (int j = i + 1; j < system->size; j++) {
      if (check_collision(&system->particles[i], &system->particles[j])) {
        resolve_collision(&system->particles[i], &system->particles[j]);
      }
    }
  }

  // update particles
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

int check_collision(Particle *p1, Particle *p2) {
  // https://www.jeffreythompson.org/collision-detection/circle-circle.php
  float radius_sum = p1->radius + p2->radius;
  float dist_sqr = distance_squared(p1->position, p2->position);
  return dist_sqr <= radius_sum * radius_sum;
}
