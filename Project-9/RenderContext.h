#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "linmath.h"

#include "./programs.h"

struct RenderContext {
  RenderContext(FlatProgram& program_, mat4x4& mvp_) :
      program(&program_), mvp(&mvp_) {}
  FlatProgram* program;
  mat4x4* mvp;
};
