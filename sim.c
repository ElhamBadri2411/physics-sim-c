#include "sim.h"
/** GLAD BEFORE GLFW **/
#include <glad/glad.h>
/** GLAD BEFORE GLFW **/
#include "particle.h"
#include "particle_system.h"
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
  Particle p;

  init_particle(&p, new_vec2(10, 10), new_vec2(10, 10), 10);

  // adding some particles
  add_particle(&system, p);

  while (!glfwWindowShouldClose(window)) {

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
