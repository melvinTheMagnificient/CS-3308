//Melissa Coblentz
//------------------------------------------------------------
//
// CS 3308
// Project 9 - Asteroids II
//
// In this project you will implement the "asteroids" video
// game or something similar. Use your imagination to make
// it awesome. You most likely will want to use your code
// from the first Asteroids project.
//
// This codebase has a new class -- Triangle. It will assist
// you in drawing triangles on the screen. See Game::frame()
// for how to use it. This codebase also has an Asteroid
// class and the Game class maintains a list of asteroids.
// You may use this code or replace it with your own as you
// see fit.
//
// A few additional helpful things:
//   * atan2(y, x) returns the angle given a right triangle
//     with base length x and height y.
//   * collision detection can be done with the dist() function:
//         inline float dist(const float2& p, const float2& q) {
//           return length(p-q);
//         }
//     A point collides with a circle if its distance from
//     the circle is less than the circle's radius.
//   * To remove asteroids, you can either mark the asteroid
//     as destroyed or you can use a list instead of a vector
//     and remove it. To remove an asteroid from a list:
//         for (list<Asteroid>::iterator it = _asteroids.begin();
//              it != _asteroids.end();
//              it++) {
//           Asteroid& a = *it;
//           if (/* asteroid hit by missile */) {
//             _asteroids.erase(it);
//           }
//         }  
//   * When you are ready for truly random behavior, add the
//     following to main():
//         srand(clock());
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
#include "./Triangle.h"
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
Triangle* Triangle::_instance = 0;
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