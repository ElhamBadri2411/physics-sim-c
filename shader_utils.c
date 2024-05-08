#include "shader_utils.h"
#include <stdio.h>
#include <stdlib.h>

char *readShaderSource(const char *shaderFile) {
  FILE *fp = fopen(shaderFile, "rb");

  if (!fp) {
    perror("error opening shader file");
    return NULL;
  }

  fseek(fp, 0L, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0l, SEEK_SET);

  char *buffer = (char *)malloc(fsize + 1);
  if (buffer == NULL) {
    fclose(fp);
    perror("failed to allocate memory for shader");
    return NULL;
  }

  fread(buffer, fsize, 1, fp);
  buffer[fsize] = '\0';
  fclose(fp);

  return buffer;
}

GLuint loadShader(const char *vertex_path, const char *frag_path) {}
