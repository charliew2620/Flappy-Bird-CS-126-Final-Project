#pragma once

#include <iostream>

#include "cinder/gl/gl.h"

namespace flappybird {

using glm::vec2;

class Bird {

 public:
  Bird(const vec2 &position, const vec2 &velocity, const vec2& acceleration, const std::string &color, const double radius,
       const double mass);
  
  void Draw();
  
  void UpdateBird();
  
  // getters
  const vec2& GetPosition() const;
  const vec2& GetVelocity() const;
  const vec2& GetAcceleration() const;
  const std::string& GetColor() const;
  const double& GetRadius() const;
  const double& GetMass() const;
  

 private:
  vec2 position_;
  vec2 velocity_;
  vec2 acceleration_;
  std::string color_;
  double radius_;
  double mass_;

};
}