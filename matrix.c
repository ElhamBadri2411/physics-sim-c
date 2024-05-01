
#include "matrix.h"
#include <math.h>

// Define and initialize the identity matrix
const mat3 IDENTITY_MATRIX = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
const mat3 ZERO_MATRIX = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

mat3 mat3_mult(const mat3 a, const mat3 b) {
  mat3 res = {0};
  res = ZERO_MATRIX;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        res.m[i][j] += a.m[i][k] * b.m[k][j];
      }
    }
  }

  return res;
}

mat3 translate_matrix(float x, float y) {
  mat3 res = IDENTITY_MATRIX;
  res.m[0][2] = x;
  res.m[1][2] = y;
  return res;
}

mat3 rotate_matrix(float angle_rad) {
  mat3 res = IDENTITY_MATRIX;

  float c = cos(angle_rad);
  float s = sin(angle_rad);

  res.m[0][0] = c;
  res.m[0][1] = -s;
  res.m[1][0] = s;
  res.m[1][1] = c;

  return res;
}

mat3 scale_matrix(float sx, float sy) {
  mat3 res = IDENTITY_MATRIX;
  res.m[0][0] = sx;
  res.m[1][1] = sy;
  return res;
}
