#include <iostream>
#include "vector2.h"
#include <chrono>
#include <thread>
#include "ball.h"
using namespace std;

const int screenWidth = 60;
const int screenHeight = 50;

const int circleXpos = 5;
const int circleYpos = 10;
const int radius = 6;

const float initialXVelocity = 3.0;
const float initialYVelocity = 5.0;

// positive x gravity pulls to the right
// negative x gravity pulls to the left
const float xGravity = 0.0;

// positive y gravity pulls to the down
// negative y gravity pulls to the up
const float yGravity = 5.0;

const float bounciness = 0.95;

const float FPS = 30.0;
const float deltaTime = 1 / FPS;

int main() {
  Ball ball (Vector2(circleXpos, circleYpos), radius);
  Vector2 ballVelocity (initialXVelocity, initialYVelocity);
  
  Display display (screenWidth, screenHeight);

  while (true) {
    
    ball.Draw (&display);
    display.Show();

    Vector2 gravity (xGravity, yGravity);
    gravity *= deltaTime;
    
    ballVelocity += gravity;
    ball.position += ballVelocity;

    if (ball.position.y - ball.radius < 0) {
      ballVelocity.x *= bounciness;
      ballVelocity.y *= -bounciness;
      ball.position.y = 0 + ball.radius;
    }

    if (ball.position.y + ball.radius > screenHeight) {
      ballVelocity.x *= bounciness;
      ballVelocity.y *= -bounciness;
      ball.position.y = screenHeight - ball.radius;
    }


    if (ball.position.x + ball.radius > screenWidth) {
      ballVelocity.x *= -bounciness;
      ballVelocity.y *= bounciness;
      ball.position.x = screenWidth - ball.radius;
    }
    else if (ball.position.x - ball.radius < 0) {
      ballVelocity.x *= -bounciness;
      ballVelocity.y *= bounciness;
      ball.position.x = 0 + ball.radius;
    }

    this_thread::sleep_for(std::chrono::milliseconds((int)(deltaTime * 1000)));

    display.Clear();
  }
  

  display.Show();
}