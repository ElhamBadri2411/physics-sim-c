#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

// glad first
#include <glad/glad.h>
// the gl
#include <GL/gl.h>

GLuint loadShader(const char *vertex_path, const char *frag_path);

#endif // !SHADER_UTILS_H
