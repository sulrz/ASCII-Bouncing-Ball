#include <iostream>
#include "vector2.h"
#include "display.h"
using namespace std;

#ifndef BALL_H
#define BALL_H

class Ball {
  public:
    Vector2 position;
    float radius;

    Ball ();
    Ball (int x, int y, float radius);
    Ball (Vector2 position, float radius);
    
    void Draw (Display *display);
};

#endif