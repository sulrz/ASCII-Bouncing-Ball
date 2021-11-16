#include <iostream>
using namespace std;

#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
  public:
    float x;
    float y;

    Vector2 ();
    Vector2 (float x, float y);
    
    
    static float DistanceSquared (Vector2 v1, Vector2 v2);
    static float Distance (Vector2 v1, Vector2 v2);
    static Vector2 Add (Vector2 source, float addition);
    static Vector2 Add (Vector2 source, Vector2 addition);
    static Vector2 Subtract (Vector2 source, float subtractor);
    static Vector2 Subtract (Vector2 source, Vector2 subtractor);
    static Vector2 Multiply (Vector2 source, float multiplier);
    static Vector2 Multiply (Vector2 source, Vector2 multiplier);
};

#endif