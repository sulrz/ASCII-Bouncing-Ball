#include <iostream>
#include "vector2.h"
#include <chrono>
#include <thread>
#include "ball.h"
using namespace std;

int width = 100;
int height = 60;

int circleXpos = 0;
int circleYpos = 10;
int radius = 6;

float initialXballVelocity = 1.3;
float initialYballVelocity = 0.0;

// positive x gravity pulls to the right
// negative x gravity pulls to the left
float xGravity = 0.0;

// positive y gravity pulls to the down
// negative y gravity pulls to the up
float yGravity = 5.0;

float lossOfEnergyPerCollision = 0.80;

float FPS = 15.0;
float deltaTime = 1 / FPS;

int main() {
  Ball ball (Vector2(circleXpos, circleYpos), radius);
  Vector2 ballVelocity (initialXballVelocity, initialYballVelocity);
  

  Display display (width, height);

  while (true) {
    
    ball.Draw (&display);
    display.Show();

    Vector2 gravity (xGravity, yGravity);
    gravity = Vector2::Multiply (gravity, deltaTime);
    ballVelocity = Vector2::Add (ballVelocity, gravity);
    // cout << ballVelocity.x << " " << ballVelocity.y << endl;
    ball.position = Vector2::Add (ball.position, ballVelocity);

    if (ball.position.y + ball.radius > height) {
      ballVelocity.y *= -lossOfEnergyPerCollision;
      ballVelocity.x *= lossOfEnergyPerCollision;
      ball.position.y = height - ball.radius;
    }

    this_thread::sleep_for(std::chrono::milliseconds((int)(deltaTime * 1000)));

    display.Clear();
  }
  

  display.Show();
}