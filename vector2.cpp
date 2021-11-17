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

// OPERATORS WITH FLOAT
const Vector2 operator+ (const Vector2& left, const float& right) {
  return Vector2 (left.x + right, left.y + right);
}

const Vector2 operator- (const Vector2& left, const float& right) {
  return Vector2 (left.x - right, left.y - right);
}

const Vector2 operator* (const Vector2& left, const float& right) {
  return Vector2 (left.x * right, left.y * right);
}

const Vector2 operator/ (const Vector2& left, const float& right) {
  return Vector2 (left.x / right, left.y / right);
}

// OPERATORS WITH VECTOR2
const Vector2 operator+ (const Vector2& left, const Vector2& right) {
  return Vector2 (left.x + right.x, left.y + right.y);
}

const Vector2 operator- (const Vector2& left, const Vector2& right) {
  return Vector2 (left.x - right.x, left.y - right.y);
}

const Vector2 operator* (const Vector2& left, const Vector2& right) {
  return Vector2 (left.x * right.x, left.y * right.y);
}

const Vector2 operator/ (const Vector2& left, const Vector2& right) {
  return Vector2 (left.x / right.x, left.y / right.y);
}

// OPERATORS WITH FLOAT
Vector2& operator+= (Vector2& left, const float& right) {
  left.x += right;
  left.y += right;
  return left;
}

Vector2& operator-= (Vector2& left, const float& right) {
  left.x -= right;
  left.y -= right;
  return left;
}

Vector2& operator*= (Vector2& left, const float& right) {
  left.x *= right;
  left.y *= right;
  return left;
}

Vector2& operator/= (Vector2& left, const float& right) {
  left.x /= right;
  left.y /= right;
  return left;
}

// OPERATORS WITH VECTOR2
Vector2& operator+= (Vector2& left, const Vector2& right) {
  left.x += right.x;
  left.y += right.y;
  return left;
}

Vector2& operator-= (Vector2& left, const Vector2& right) {
  left.x -= right.x;
  left.y -= right.y;
  return left;
}

Vector2& operator*= (Vector2& left, const Vector2& right) {
  left.x *= right.x;
  left.y *= right.y;
  return left;
}

Vector2& operator/= (Vector2& left, const Vector2& right) {
  left.x /= right.x;
  left.y /= right.y;
  return left;
}