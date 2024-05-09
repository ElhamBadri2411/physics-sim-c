#include "vector.h"
#include <math.h>

const vec2 ZERO_VEC = {0, 0};

vec2 new_vec2(float x, float y) {
  vec2 vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

float length(const vec2 vec) { return sqrtf(vec.x * vec.x + vec.y * vec.y); }
float dot(const vec2 a, const vec2 b) { return a.x * b.x + a.y * b.y; }
float relative_length(const vec2 vec) { return vec.x * vec.x + vec.y * vec.y; }

vec2 add(const vec2 a, const vec2 b) { return new_vec2(a.x + b.x, a.y + b.y); }
vec2 sub(const vec2 a, const vec2 b) { return new_vec2(a.x - b.x, a.y - b.y); }
vec2 neg(const vec2 vec) { return new_vec2(-vec.x, -vec.y); }

vec2 mult(float s, const vec2 vec) { return new_vec2(vec.x * s, vec.y * s); }
vec2 normalized(const vec2 vec) {
  float inverse_len = 1 / length(vec);
  if (inverse_len == 1) {
    return vec;
  }
  return mult(inverse_len, vec);
}
// 2 crossed vectors return a scalar pointing in the z direction
float cross(const vec2 a, const vec2 b) { return a.x * b.y - a.y * b.x; }
// vector crossed with scalar returns vector on 2D plane
vec2 cross_vec(const vec2 vec, float s) {
  return new_vec2(s * vec.y, -s * vec.x);
}
vec2 cross_c(float s, const vec2 vec) {
  return new_vec2(-s * vec.y, s * vec.x);
}
vec2 rotate(const vec2 vec, float rad) {
  float c = cos(rad);
  float s = sin(rad);
  return new_vec2(vec.x * c - vec.y * s, vec.x * s + vec.y * c);
}

vec2 project(const vec2 vec, const vec2 axis) {
  float magnitude_squared = relative_length(axis);
  if (magnitude_squared == 0) {
    return new_vec2(0, 0);
  }

  float projection_scalar = dot(vec, axis) / magnitude_squared;
  return mult(projection_scalar, vec);
}

float distance(const vec2 a, const vec2 b) { return length(sub(a, b)); }
float distance_squared(const vec2 a, const vec2 b) {
  vec2 diff = sub(a, b);
  return dot(diff, diff);
}

vec2 transform(const mat3 m, const vec2 vec) {
  vec2 result;

  result.x = m.m[0][0] * vec.x + m.m[0][1] * vec.y + m.m[0][2];
  result.y = m.m[1][0] * vec.x + m.m[1][1] * vec.y + m.m[1][2];

  return result;
}
