//Melissa Coblentz
#pragma once

#include <vector>
#include <list>

#include "./RenderContext.h"
#include "./Asteroid.h"
#include "./Rocket.h"
#include "./Bullet.h"
#include "./Color.h"

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

  void RocketCollisions(Asteroid& a);

  bool BulletAsteroidCollisions(Asteroid& a);

  void GameOver();

  void MakeBullet();

  bool AreTouching(Asteroid& a, Asteroid& b);

  bool AreTouching(Asteroid& a, Bullet& b);

  bool IsTouchingRocket(Asteroid& a);

  bool OffScreen(float2 f);

 private:
  std::list<Asteroid> _asteroids;  
  std::list<Bullet> _bullets;
  Rocket* _rocket;
  float _x;
  float _y;
};