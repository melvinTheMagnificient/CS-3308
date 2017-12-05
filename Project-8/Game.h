//Melissa Coblentz
#pragma once

#include <vector>

#include "./RenderContext.h"
#include "./float2.h"
#include "./Color.h"

class Game {
 public:
  Game();

  void frame(RenderContext& context, const float elapsed);

  void keyCallback(int key, int action, int mods);

  void mouseButtonCallback(int button, int action, int mods,
                           double x, double y);

  void cursorPositionCallback(double x, double y);
private:
	float2 _astroidPosition;
	float2 _astroidVelocity;	
	float _astroidSize;
	Color _astroidColor;
};