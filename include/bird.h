#pragma once

#include <iostream>

#include "cinder/gl/gl.h"
#include "cinder/app/RendererGl.h"

namespace flappybird {

using glm::vec2;

class Bird {

 public:
  /**
   * Constructor to initialize a Bird object.
   */
  Bird(const int &window_size, const ci::gl::Texture2dRef &bird_image, const vec2 &spawn_position);

  Bird() = default;

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

  const ci::Rectf &GetBody() const;

 private:
  vec2 position_;
  float velocity_;
  float acceleration_;
  float kGravity = 0.4f;
  std::string kColor = "yellow";
  float kRadius = 20;

  float kRatio = 20;

  int window_size_;

  ci::Rectf body_;

  ci::gl::Texture2dRef texture_;

  /**
   * Updates the body of the bird's position.
   */
  void UpdateBody();

};
}