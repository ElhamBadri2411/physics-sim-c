
#include "particle.h"

void init_particle(Particle *p, vec2 position, vec2 velocity, float mass) {
  p->position = position;
  p->velocity = velocity;
  p->acceleration = new_vec2(0, 0);
  p->mass = mass;
}

void update_particle(Particle *p, float dt) {
  // Update velocity based on acceleration
  p->velocity = add(p->velocity, mult(dt, p->acceleration));
  // Update position based on velocity
  p->position = add(p->position, mult(dt, p->velocity));
  // Reset acceleration after each update
  p->acceleration = new_vec2(0, 0);
}

void apply_force(Particle *p, vec2 force) {
  // F = ma, or a = F/m
  vec2 acceleration = mult(1 / p->mass, force);
  p->acceleration = add(p->acceleration, acceleration);
}

void reset_particle(Particle *p) {
  p->velocity = new_vec2(0, 0);
  p->acceleration = new_vec2(0, 0);
}
