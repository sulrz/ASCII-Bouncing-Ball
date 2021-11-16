#include <iostream>
#include "vector2.h"
#include "display.h"
#include <string>
using namespace std;

Display :: Display () {
  this->size.x = 0.0;
  this->size.y = 0.0;

  vector<vector<int>> newGrid (64, vector<int>(32, 0));
  grid = newGrid;

  this->Clear();
}

Display :: Display (int width, int height) {
  this->size.x = width;
  this->size.y = height;

  vector<vector<int>> newGrid (height, vector<int>(width, 0));
  grid = newGrid;

  this->Clear();
}

Display :: Display (Vector2 size) {
  this->size = size;

  vector<vector<int>> newGrid (size.y, vector<int>(size.x, 0));
  grid = newGrid;

  this->Clear();
}

void Display :: Clear () {
  // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
  std::cout<< u8"\033[2J\033[1;1H"; 
  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      grid[i][j] = 0;
    }
  }
}

void Display :: Show () {
  
  for (int i = 0; i < size.y; i+=2) {
    if (i + 1 >= size.y) break;

    string line;

    for (int j = 0; j < size.x; j++) {
      line += chars[grid[i][j]][grid[i+1][j]];
    }
    cout << line;
    printf ("\n");
    // cout.flush();
  }
}