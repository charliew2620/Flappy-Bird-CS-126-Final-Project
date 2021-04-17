#include <bird.h>

namespace flappybird {

Bird::Bird(const glm::vec2 &position,
           const glm::vec2 &velocity,
           const vec2 &acceleration,
           const std::string &color,
           const double radius,
           const double mass) {
  position_ = position;
  velocity_ = velocity;
  acceleration_ = acceleration;
  color_ = color;
  radius_ = radius;
  mass_ = mass;

}

void Bird::Draw() {
  ci::gl::color(ci::Color(color_.c_str()));
  ci::gl::drawSolidCircle(vec2(position_), (float) radius_);
}

void Bird::UpdateBird() {
  position_++;
}

const vec2 &Bird::GetPosition() const {
  return position_;
}

const vec2 &Bird::GetVelocity() const {
  return velocity_;
}
const vec2 &Bird::GetAcceleration() const {
  return acceleration_;
}
const std::string &Bird::GetColor() const {
  return color_;
}

const double &Bird::GetRadius() const {
  return radius_;
}

const double &Bird::GetMass() const {
  return mass_;
}
}
