#include <iostream>
#include <vector>
#include "vector2.h"
using namespace std;

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
  public:
    char chars[2][2] = {
      {' ', '_'},
      {'^', 'C'}
    };
    Vector2 size;
    vector<vector<int>> grid;
    
    Display ();
    Display (int width, int height);
    Display (Vector2 size);

    Vector2 getSize ();

    void Clear ();
    void Show ();

};

#endif