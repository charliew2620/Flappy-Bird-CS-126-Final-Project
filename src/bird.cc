#include <bird.h>

namespace flappybird {

Bird::Bird(const int &window_size, const ci::gl::Texture2dRef &bird_image, const vec2 &spawn_position) {
  acceleration_ = 0;
  velocity_ = 0;
  position_ = spawn_position;
  window_size_ = window_size;
  texture_ = bird_image;

  UpdateBody();
}

void Bird::Draw() {
  ci::gl::color(1, 1, 1);
  ci::gl::draw(texture_, body_);
}

void Bird::UpdateBird() {
  if (position_.y + kRadius >= (float) window_size_) {
    position_.y = (float) window_size_;
    velocity_ = 0;
    acceleration_ = 0;

  } else {
    acceleration_ = kGravity;
    velocity_ += acceleration_;
    position_.y += velocity_;
  }
  UpdateBody();
}

void Bird::ChangeBirdOnSpace() {
  acceleration_ = 0;
  velocity_ = -kGravity * kRatio;
  position_.y += velocity_;

  UpdateBody();

}

void Bird::UpdateBody() {
  body_ = ci::Rectf(vec2(position_.x - kRadius, position_.y - kRadius),
                    vec2(position_.x + kRadius, position_.y + kRadius));
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

const float &Bird::GetAcceleration() const {
  return acceleration_;
}

const ci::Rectf &Bird::GetBody() const {
  return body_;
}

}