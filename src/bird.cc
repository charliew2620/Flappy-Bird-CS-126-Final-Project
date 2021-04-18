#include <bird.h>

namespace flappybird {

Bird::Bird() {
  acceleration_ = 0;
  velocity_ = 0;
  position_ = kSpawnPosition;
}

void Bird::Draw() {
  ci::gl::color(ci::Color(kColor.c_str()));
  ci::gl::drawSolidCircle(vec2(position_), kRadius);
}

void Bird::UpdateBird() {
  if (acceleration_ >= kGravity) {
    acceleration_ = kGravity;

  } else {
    acceleration_ += kGravity;
  }
  velocity_ += acceleration_;
  position_.y += velocity_;
  Draw();
}

void Bird::ChangeBirdOnSpace() {
  acceleration_ = 0;
  velocity_ = -kGravity * kRatio;
  position_.y += velocity_;
  Draw();
}

const vec2 &Bird::GetPosition() const {
  return position_;
}

const float &Bird::GetVelocity() const {
  return velocity_;
}

const std::string &Bird::GetColor() const {
  return kColor;
}

const float &Bird::GetRadius() const {
  return kRadius;
}

}
