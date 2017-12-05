#pragma once

#include <vector>
#include <list>

#include "./RenderContext.h"
#include "./Asteroid.h"

class Game {
 public:
  Game();

  void frame(RenderContext& context, const float elapsed);

  void keyCallback(int key, int action, int mods);

  void mouseButtonCallback(int button, int action, int mods,
                           double x, double y);

  void cursorPositionCallback(double x, double y);

  void WallBounce(Asteroid& a);

  void AsteroidCollisions(Asteroid& a);

 private:
  std::list<Asteroid> _asteroids;
};
