#pragma once

#include <stdexcept>
#include <cmath>
#include <iostream>


union float2 {
  struct { float s[2]; };
  struct { float x, y; };
  float2(float x_, float y_) : x(x_), y(y_) {}
  float2() : x(0), y(0) {}
};


//------------------------------------------------------------
// output operators
inline std::ostream& operator<<(std::ostream& out, const float2& v) {
  for (int i = 0; i < 2; i++) {
    out << v.s[i];
    if (i < 1) out << " ";
  }
  return out;
}

//------------------------------------------------------------
inline float2 operator/(const float2 v, const float f) {
  return float2(v.x/f, v.y/f);
}

//------------------------------------------------------------
inline float2 operator*(const float2 v, const float f) {
  return float2(v.x*f, v.y*f);
}

//------------------------------------------------------------
inline float2 operator+(const float2 v, const float f) {
  return float2(v.x+f, v.y+f);
}

//------------------------------------------------------------
inline float2 operator-(const float2 v, const float f) {
  return float2(v.x-f, v.y-f);
}

//------------------------------------------------------------
inline float2 operator+(const float2 v, const float2 u) {
  return float2(v.x+u.x, v.y+u.y);
}

//------------------------------------------------------------
inline float2 operator-(const float2 v, const float2 u) {
  return float2(v.x-u.x, v.y-u.y);
}

//------------------------------------------------------------
// dot
inline float dot(const float2 u, const float2 v) {
  return u.x * v.x + u.y * v.y;
}

//------------------------------------------------------------
// length2
inline float length2(const float2 v) {
  return dot(v, v);
}

//------------------------------------------------------------
// length
inline float length(const float2 v) {
  return sqrt(length2(v));
}

//------------------------------------------------------------
// normalize
inline float2 normalize(const float2 v) {
  return v / length(v);
}
inline float2 unit(const float2 v) {
  return v / length(v);
}

