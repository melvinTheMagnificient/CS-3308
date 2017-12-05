#pragma once

#include <random>

// To render in white, use Color::WHITE.
struct Color {
  Color() : r(0), g(0), b(0) {}
  Color(float r_, float g_, float b_) : r(r_), g(g_), b(b_) {}
  float r, g, b;

  static Color random() {
    return Color(rand()/(float)RAND_MAX, rand()/(float)RAND_MAX,
                 rand()/(float)RAND_MAX);
  }

  static Color WHITE;
  static Color BLACK;
  static Color GRAY;
  static Color RED;
  static Color GREEN;
  static Color BLUE;
};

