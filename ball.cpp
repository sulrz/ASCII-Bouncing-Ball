#include <iostream>
#include "vector2.h"
#include "ball.h"
#include "display.h"
using namespace std;

Ball :: Ball () {
  this->position.x = 0.0;
  this->position.y = 0.0;
  this->radius = 5.0;
}

Ball :: Ball (Vector2 position, float radius) {
  this->position = position;
  this->radius = radius;
}

Ball :: Ball (int x, int y, float radius) {
  this->position.x = x;
  this->position.y = y;
  this->radius = radius;
}

void Ball :: Draw (Display *display) {
  Vector2 leftTop = this->position - radius;
  Vector2 rightBot = this->position + radius;

  for (int i = leftTop.y; i < rightBot.y; i++) {
    for (int j = leftTop.x; j < rightBot.x; j++) {
      if (i < 0 or i > display->size.y) continue;
      if (j < 0 or j > display->size.x) continue;

      if (Vector2::DistanceSquared(position, Vector2(j, i)) <= radius * radius) {
        display->grid[i][j] = 1;
      }
    }
  }
}