
#include "graphics_utils.h"

void ortho(float left, float right, float bottom, float top, float nearVal,
           float farVal, float *projMatrix) {
  float ral = right + left;
  float rsl = right - left;
  float tab = top + bottom;
  float tsb = top - bottom;
  float fan = farVal + nearVal;
  float fsn = farVal - nearVal;

  projMatrix[0] = 2.0f / rsl;
  projMatrix[1] = 0.0f;
  projMatrix[2] = 0.0f;
  projMatrix[3] = 0.0f;

  projMatrix[4] = 0.0f;
  projMatrix[5] = 2.0f / tsb;
  projMatrix[6] = 0.0f;
  projMatrix[7] = 0.0f;

  projMatrix[8] = 0.0f;
  projMatrix[9] = 0.0f;
  projMatrix[10] = -2.0f / fsn;
  projMatrix[11] = 0.0f;

  projMatrix[12] = -ral / rsl;
  projMatrix[13] = -tab / tsb;
  projMatrix[14] = -fan / fsn;
  projMatrix[15] = 1.0f;
}
