#include <iostream>
#include <cmath>
#include "vector2.h"
using namespace std;

Vector2 :: Vector2 () {
  this->x = 0.0;
  this->y = 0.0;
}

Vector2 :: Vector2 (float x, float y) {
  this->x = x;
  this->y = y;
}


float Vector2 :: DistanceSquared (Vector2 v1, Vector2 v2) {
  float dy = abs (v1.y - v2.y);
  float dx = abs (v1.x - v2.x);

  return dx*dx + dy*dy;
}

float Vector2 :: Distance (Vector2 v1, Vector2 v2) {
  float dy = abs (v1.y - v2.y);
  float dx = abs (v1.x - v2.x);

  return sqrt (dx*dx + dy*dy);
}

Vector2 Vector2 :: Add (Vector2 source, float addition) {
  source.x += addition;
  source.y += addition;

  return source;
}

Vector2 Vector2 :: Add (Vector2 source, Vector2 addition) {
  source.x += addition.x;
  source.y += addition.y;

  return source;
}

Vector2 Vector2 :: Subtract (Vector2 source, float subtractor) {
  source.x -= subtractor;
  source.y -= subtractor;

  return source;
}

Vector2 Vector2 :: Subtract (Vector2 source, Vector2 subtractor) {
  source.x -= subtractor.x;
  source.y -= subtractor.y;

  return source;
}

Vector2 Vector2 :: Multiply (Vector2 source, float multiplier) {
  source.x *= multiplier;
  source.y *= multiplier;

  return source;
}

Vector2 Vector2 :: Multiply (Vector2 source, Vector2 multiplier) {
  source.x *= multiplier.x;
  source.y *= multiplier.y;

  return source;
}