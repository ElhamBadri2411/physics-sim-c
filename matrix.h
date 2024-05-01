#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix_3d {
  float m[3][3];
} mat3;

extern const mat3 IDENTITY_MATRIX;
extern const mat3 ZERO_MATRIX;

mat3 mat3_mult(const mat3 a, const mat3 b);
mat3 translate_matrix(float x, float y);
mat3 rotate_matrix(float angle_rad);
mat3 scale_matrix(float sx, float sy);

#endif // !MATRIX_H
