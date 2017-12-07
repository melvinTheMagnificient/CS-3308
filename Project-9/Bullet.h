//Melissa Coblentz
#pragma once

#include "./float2.h"
#include "./Color.h"

class Bullet {
 public:
  Bullet(const float2& position, const float2& velocity) {
    _position = position;
    _velocity = velocity;
    _size = .01;
    _color = Color::BLACK;
  }

  //modifies position based on velocity (called every frame)
  void move() {
    _position = _position + _velocity;
  }

  float2 getPos() const { return _position; }
  void setPos(const float2& position) { _position = position; }
  float2 getVel() const { return _velocity; }
  void setVel(const float2& velocity) { _velocity = velocity; }
  float getSize() const { return _size; }
  Color getColor() const { return _color; }

 private:
  //data members based on circle data members
  float2 _position;
  float2 _velocity;
  float _size;
  Color _color;
};
