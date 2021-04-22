#pragma once

#include <iostream>

#include "cinder/gl/gl.h"

namespace flappybird {

using glm::vec2;

class Bird {

 public:
  /**
   * Constructor to initialize a Bird object.
   */
  Bird();

  /**
   * Displays the bird in its current position.
   */
  void Draw();

  /**
   * Updates the bird's position, velocity, and acceleration.
   */
  void UpdateBird();

  /**
   * Resets the bird's acceleration and negates the velocity.
   */
  void ChangeBirdOnSpace();

  // getters
  const vec2 &GetPosition() const;
  const float &GetVelocity() const;
  const float &GetAcceleration() const;
  const std::string &GetColor() const;
  const float &GetRadius() const;

 private:
  vec2 position_;
  float velocity_;
  float acceleration_;
  float kGravity = 0.4f;
  std::string kColor = "yellow";
  float kRadius = 20;

  float kRatio = 20;
  
  bool has_collided_ = false;

  vec2 kSpawnPosition = vec2(300, 450);

};
}