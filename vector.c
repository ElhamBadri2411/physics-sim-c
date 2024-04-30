#include "vector.h"
#include <math.h>

vec2 new_vec2(float x, float y) {
  vec2 vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

float length(vec2 vec) { return sqrtf(vec.x * vec.x + vec.y * vec.y); }
float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
float relative_length(vec2 vec) { return vec.x * vec.x + vec.y * vec.y; }

vec2 add(vec2 a, vec2 b) { return new_vec2(a.x + b.x, a.y + b.y); }
vec2 sub(vec2 a, vec2 b) { return new_vec2(a.x - b.x, a.y - b.y); }
vec2 neg(vec2 vec) { return new_vec2(-vec.x, -vec.y); }

vec2 mult(float s, vec2 vec) { return new_vec2(vec.x * s, vec.y * s); }
vec2 normalized(vec2 vec) {
  float inverse_len = 1 / length(vec);
  if (inverse_len == 1) {
    return vec;
  }
  return mult(inverse_len, vec);
}
// 2 crossed vectors return a scalar pointing in the z direction
float cross(vec2 a, vec2 b) { return a.x * b.y - a.y * b.x; }
// vector crossed with scalar returns vector on 2D plane
vec2 cross_vec(vec2 vec, float s) { return new_vec2(s * vec.y, -s * vec.x); }
vec2 cross_c(float s, vec2 vec) { return new_vec2(-s * vec.y, s * vec.x); }
