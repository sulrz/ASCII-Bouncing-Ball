#include <iostream>
#include "vector2.h"
#include <chrono>
#include <thread>
#include "ball.h"
using namespace std;

const int screenWidth = 50;
const int screenHeight = 40;

const int circleXpos = 20;
const int circleYpos = 10;
const int radius = 6;

const float initialXVelocity = 2.0;
const float initialYVelocity = 2.0;

// positive x gravity pulls to the right
// negative x gravity pulls to the left
const float xGravity = 0.0;

// positive y gravity pulls to the down
// negative y gravity pulls to the up
const float yGravity = 5;

const float bounciness = 0.90;

const float FPS = 30.0;
const float deltaTime = 1 / FPS;

int main() {
  Ball ball (Vector2(circleXpos, circleYpos), radius);
  // Ball ball1 (Vector2(30, 40), radius);
  Vector2 ballVelocity (initialXVelocity, initialYVelocity);
  // Vector2 ball1Velocity (-initialXVelocity, initialYVelocity);
  
  Display display (screenWidth, screenHeight);

  Vector2 gravity (xGravity, yGravity);
  gravity *= deltaTime;

  while (true) {
    display.Clear();

    ball.Draw (&display);
    // ball1.Draw (&display);
    display.Show();
    
    ballVelocity += gravity;
    // ball1Velocity += gravity;
    ball.position += ballVelocity;
    // ball1.position += ball1Velocity;

    // if (Vector2::DistanceSquared(ball.position, ball1.position) <= (ball.radius + ball1.radius) * (ball.radius + ball1.radius)) {
    //   ballVelocity *= -bounciness;

    //   ball1Velocity *= -bounciness;
    // }

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
    
    if (ball.position.x - ball.radius < 0) {
      ballVelocity.x *= -bounciness;
      ballVelocity.y *= bounciness;
      ball.position.x = 0 + ball.radius;
    }

    // if (ball1.position.y - ball1.radius < 0) {
    //   ball1Velocity.x *= bounciness;
    //   ball1Velocity.y *= -bounciness;
    //   ball1.position.y = 0 + ball1.radius;
    // }

    // if (ball1.position.y + ball1.radius > screenHeight) {
    //   ball1Velocity.x *= bounciness;
    //   ball1Velocity.y *= -bounciness;
    //   ball1.position.y = screenHeight - ball1.radius;
    // }

    // if (ball1.position.x + ball1.radius > screenWidth) {
    //   ball1Velocity.x *= -bounciness;
    //   ball1Velocity.y *= bounciness;
    //   ball1.position.x = screenWidth - ball1.radius;
    // }
    
    // if (ball1.position.x - ball1.radius < 0) {
    //   ball1Velocity.x *= -bounciness;
    //   ball1Velocity.y *= bounciness;
    //   ball1.position.x = 0 + ball1.radius;
    // }

    this_thread::sleep_for(std::chrono::milliseconds((int)(deltaTime * 1000)));
  }

  return 0;
}