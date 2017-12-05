//------------------------------------------------------------
//
// CS 3308
// Project 8 - Asteroids I
//
// In this project you will render multiple "asteroids"
// flying across the screen. To get 90% of the points you
// must have at least 10 balls of varying size and color
// move across the screen in random directions and at random
// speeds. For the final 10% of the points you must do
// something cool, like have the circles bounce off the walls
// or change size or color as they fly or bounce off each
// other, etc.
//
// See youtu.be/vP89WaCW8jo for a video of what you need to
// do to get the 90% base grade.
//
// You will most likely not modify main.cpp. Most of the work
// will be done in Game.h, Game.cpp and any other files you
// create. See the notes for l24 posted online for additional
// helps.
//
// Submit a zipped copy of all of your files.
// 
//------------------------------------------------------------
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <vector>

#include "./util.h"
#include "./Circle.h"
#include "./Line.h"
#include "./programs.h"
#include "./float2.h"
#include "./Game.h"

Color Color::WHITE = Color(1, 1, 1);
Color Color::BLACK = Color(0, 0, 0);
Color Color::GRAY = Color(0.7, 0.7, 0.7);
Color Color::RED = Color(1, 0, 0);
Color Color::GREEN = Color(0, 1, 0);
Color Color::BLUE = Color(0, 0, 1);

Circle* Circle::_instance = 0;
Line* Line::_instance = 0;

static const int WIDTH = 640;
static const int HEIGHT = 480;

GLFWwindow* window;
float wratio;

clock_t lastTime = 0;
Game game;

static void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(
    GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);

  game.keyCallback(key, action, mods);
}

float2 win2obj(double xwin, double ywin) {
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);

  return float2(wratio*2*(xwin/(double)WIDTH)-wratio, 0-(2*(ywin/(double)HEIGHT)-1));
}

bool moving = false;
void mouse_button_callback(
    GLFWwindow* window, int button, int action, int mods) {
  using namespace std;
  double x, y;
  glfwGetCursorPos(window, &x, &y);
  float2 p = win2obj(x, y);
  game.mouseButtonCallback(button, action, mods, p.x, p.y);
}

void cursor_pos_callback(GLFWwindow* window, double x, double y) {
  float2 p = win2obj(x, y);
  game.cursorPositionCallback(p.x, p.y);
}

void render(FlatProgram& program) {
  mat4x4 m, p, mvp;

  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  mat4x4_identity(m);
  mat4x4_ortho(p, -wratio, wratio, -1.f, 1.f, 1.f, -1.f);
  mat4x4_mul(mvp, p, m);

  glUseProgram(program.program);
  glUniformMatrix4fv(program.mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);

  clock_t t = clock();
  float elapsed = 0;
  if (lastTime > 0) {
    elapsed = (t - lastTime) / (double)CLOCKS_PER_SEC;
  }
  lastTime = t;

  RenderContext context(program, mvp);
  game.frame(context, elapsed);
}

int main(void) {
  using namespace std;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
    exit(EXIT_FAILURE);

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(WIDTH, HEIGHT, "Asteroids", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(window, key_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);

  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  glfwSwapInterval(1);

  Circle::instance();
  Line::instance();

  FlatProgram program;

  while (!glfwWindowShouldClose(window)) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    wratio = width / (float) height;
    glViewport(0, 0, width, height);

    render(program);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();
  exit(EXIT_SUCCESS);
}
