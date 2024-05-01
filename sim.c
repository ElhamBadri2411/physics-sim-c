#include "sim.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#define pi 3.14

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

  while (!glfwWindowShouldClose(window)) {

    glClear(GL_COLOR_BUFFER_BIT);

    // DRAW HERE

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
