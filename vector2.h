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

    friend const Vector2 operator+ (const Vector2& left, const float& right);
    friend const Vector2 operator- (const Vector2& left, const float& right);
    friend const Vector2 operator* (const Vector2& left, const float& right);
    friend const Vector2 operator/ (const Vector2& left, const float& right);

    friend const Vector2 operator+ (const Vector2& left, const Vector2& right);
    friend const Vector2 operator- (const Vector2& left, const Vector2& right);
    friend const Vector2 operator* (const Vector2& left, const Vector2& right);
    friend const Vector2 operator/ (const Vector2& left, const Vector2& right);

    friend Vector2& operator+= (Vector2& left, const float& right);
    friend Vector2& operator-= (Vector2& left, const float& right);
    friend Vector2& operator*= (Vector2& left, const float& right);
    friend Vector2& operator/= (Vector2& left, const float& right);

    friend Vector2& operator+= (Vector2& left, const Vector2& right);
    friend Vector2& operator-= (Vector2& left, const Vector2& right);
    friend Vector2& operator*= (Vector2& left, const Vector2& right);
    friend Vector2& operator/= (Vector2& left, const Vector2& right);
};

#endif