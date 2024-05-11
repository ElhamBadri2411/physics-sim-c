#include "sim.h"
/** GLAD BEFORE GLFW **/
#include <glad/glad.h>
/** GLAD BEFORE GLFW **/
#include "graphics_utils.h"
#include "particle.h"
#include "particle_system.h"
#include "shader_utils.h"
#include "vector.h"
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (!glfwInit()) {
    perror("glfw init failed\n");
    return -1;
  }

  GLFWwindow *window = glfwCreateWindow(800, 800, "2D Physics Sim", NULL, NULL);

  if (!window) {
    perror("Failed to open GLFW window");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    perror("glad init failed\n");
    glfwTerminate();
    return -1;
  }

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  ParticleSystem system;
  init_particle_system(&system, 100);
  Particle p, p1, p2, p3;

  init_particle(&p, new_vec2(10, 10), new_vec2(10, 10), 10);
  init_particle(&p1, new_vec2(10, 10), new_vec2(10, 10), 10);
  init_particle(&p2, new_vec2(10, 10), new_vec2(10, 10), 10);
  init_particle(&p3, new_vec2(10, 10), new_vec2(10, 10), 10);

  // adding some particles
  add_particle(&system, p);
  add_particle(&system, p1);
  add_particle(&system, p2);
  add_particle(&system, p3);
  GLuint shader_program = loadShader("./shader.vert", "./shader.frag");

  GLuint vao;
  GLuint vbo;

  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, system.size * sizeof(Particle),
               system.particles, GL_DYNAMIC_DRAW);

  // Position
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Particle),
                        (void *)offsetof(Particle, position));
  glEnableVertexAttribArray(0);

  // Radius
  glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(Particle),
                        (void *)offsetof(Particle, radius));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  // projection matrix

  float projection_matrix[16];
  ortho(0.0f, 800.0f, 800.0f, 0.0f, -1.0f, 1.0f, projection_matrix);
  int projLoc = glGetUniformLocation(shader_program, "projection");
  glUseProgram(shader_program);
  glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection_matrix);

  while (!glfwWindowShouldClose(window)) {
    glUseProgram(shader_program);
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glDrawArrays(GL_POINTS, 0, system.size); // Draw the particles
    glBindVertexArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
