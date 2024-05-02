#ifndef VECTOR_H
#define VECTOR_H
#define PI 3.14159265
#include "matrix.h"

typedef struct vector_2d {
  float x;
  float y;
} vec2;

extern const vec2 ZERO_VEC;

vec2 new_vec2(float x, float y);
float length(const vec2 vec);
float dot(const vec2 a, const vec2 b);
float relative_length(const vec2 vec);
vec2 normalized(const vec2 vec);
vec2 add(const vec2 a, const vec2 b);
vec2 sub(const vec2 a, const vec2 b);
vec2 neg(const vec2 vec);
vec2 mult(float s, const vec2 vec);
// 2 crossed vectors return a scalar pointing in the z direction
float cross(const vec2 a, const vec2 b);
// vector crossed with scalar returns vector on 2D plane
vec2 cross_vec(const vec2 vec, float s);
vec2 cross_c(float s, const vec2 vec);
// good for when doing a single rotate that doesnt need to be sone again
vec2 rotate(const vec2 vec, float angle);
vec2 project(const vec2 vec, const vec2 axis);
float distance(const vec2 a, const vec2 b);
float distance_squared(const vec2 a, const vec2 b);
vec2 transform(const mat3 m, const vec2 vec);

#endif // VECTOR_H
