#include <iostream>
#include "vector2.h"
#include "display.h"
#include <string>
#include <stdio.h>
using namespace std;

Display :: Display () {
  this->size.x = 0.0;
  this->size.y = 0.0;

  base = (char*) malloc ((32 + 2) * sizeof (char));
  for (int i = 0; i < 32 + 2; i++) base[i] = '-';

  vector<vector<int>> newGrid (64, vector<int>(32, 0));
  grid = newGrid;

  // this->Clear();
}

Display :: Display (int width, int height) {
  this->size.x = width;
  this->size.y = height;

  base = (char*) malloc ((width + 2) * sizeof (char));
  for (int i = 0; i < width + 2; i++) base[i] = '-';

  vector<vector<int>> newGrid (height, vector<int>(width, 0));
  grid = newGrid;

  // this->Clear();
}

Display :: Display (Vector2 size) {
  this->size = size;

  base = (char*) malloc ((size.x + 2) * sizeof (char));
  for (int i = 0; i < size.x + 2; i++) base[i] = '-';

  vector<vector<int>> newGrid (size.y, vector<int>(size.x, 0));
  grid = newGrid;

  // this->Clear();
}

void Display :: Clear () {
  printf ("\e[H");

  for (int i = 0; i < size.y; i++) {
    for (int j = 0; j < size.x; j++) {
      grid[i][j] = 0;
    }
  }
}

void Display :: Show () {
  char row[(int)this->size.x];

  fwrite (this->base, this->size.x + 2, 1, stdout);
  fputc ('\n', stdout);

  for (int i = 0; i < size.y; i+=2) {
    if (i + 1 >= size.y) break;

    fputc ('|', stdout);

    for (int j = 0; j < size.x; j++) {
      row[j] = chars[grid[i][j]][grid[i+1][j]];
    }

    fwrite (row, this->size.x, 1, stdout);
    fputc ('|', stdout);
    fputc ('\n', stdout);
  }
  fwrite (this->base, this->size.x + 2, 1, stdout);
}