//Melissa Coblentz
#pragma once

#include <math.h>

#include "./float2.h"
#include "./Color.h"

class Rocket {
 public:
  Rocket(const float size, const Color& color) {
    _size = size;
    _color = color;
    _theta = 0;
  }

  //Change rocket orientation counterclockwise
  void SpinRocketLeft(){
    _theta += M_PI/20;
  }
  
  //Change rocket orientation clockwise
  void SpinRocketRight(){
    _theta -= M_PI/20;
  }

  float getSize() const { return _size; }
  void setSize(const float& size) { _size = size; }
  Color getColor() const { return _color; }
  void setColor(const Color& color) { _color = color; }
  float getTheta() const { return _theta; }
  void setTheta(const float& theta) { _theta = theta; }

 private:
  //data members based on triangle data members
  float _size;
  Color _color; 
  float _theta;
};
