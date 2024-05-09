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

GLuint compileShader(const char *src, GLenum type) {

  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &src, NULL);
  glCompileShader(shader);

  int success;
  char info[256];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 256, NULL, info);
    printf("ERROR::SHADER::COMPILATION_FAILED\n%s\n", info);
  }

  return shader;
}

GLuint loadShader(const char *vertex_path, const char *frag_path) {

  char *vertex_src = readShaderSource(vertex_path);
  char *frag_src = readShaderSource(frag_path);

  GLuint vertex_shader = compileShader(vertex_src, GL_VERTEX_SHADER);
  GLuint frag_shader = compileShader(frag_src, GL_FRAGMENT_SHADER);

  free(vertex_src);
  free(frag_src);

  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, frag_shader);
  glLinkProgram(shader_program);

  int success;
  char infoLog[512];
  glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
    printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(frag_shader);

  return shader_program;
}
