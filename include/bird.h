#pragma once

#include <iostream>

#include "cinder/gl/gl.h"

namespace flappybird {

using glm::vec2;

class Bird {

 public:
  Bird();
  
  void Draw();
  
  void UpdateBird();
  
  void ChangeBirdOnSpace();
  
  // getters
  const vec2& GetPosition() const;
  const float& GetVelocity() const;
  const std::string& GetColor() const;
  const double& GetRadius() const;
  

 private:
  vec2 position_;
  float velocity_;
  float acceleration_;
  float kGravity = 0.2f;
  std::string kColor = "yellow";
  double kRadius = 10;

};
}