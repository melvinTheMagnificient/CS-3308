#pragma once

#include "./float2.h"
#include "./Color.h"

class Asteroid {
 public:
  Asteroid(const float2& p, const float2& v, const float size,
           const Color& color) {
    _p = p;
    _v = v;
    _size = size;
    _color = color;
  }

  void move() {
    _p = _p + _v;
  }

  float2 getPos() const { return _p; }
  void setPos(const float2& p) { _p = p; }
  float2 getVel() const { return _v; }
  void setVel(const float2& v) { _v = v; }
  float getSize() const { return _size; }
  void setSize(const float& size) { _size = size; }
  Color getColor() const { return _color; }
  void setColor(const Color& color) { _color = color; }

 private:
  float2 _p;
  float2 _v;
  float _size;
  Color _color;
};
