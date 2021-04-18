#include "pipe.h"

namespace flappybird {

using glm::vec2;

Pipe::Pipe(const float &width, const float &window_size, const float &margin) {
  width_ = width;
  window_size_ = window_size;
  spawn_point_ = window_size + margin;
}

void Pipe::Draw() {
  ci::gl::color(ci::Color(kColorOfPipe.c_str()));
  ci::gl::drawSolidRect(ci::Rectf(vec2(spawn_point_, 0), vec2(spawn_point_ + width_, window_size_)));
}

void Pipe::AdvanceOneFrame() {
  frames_passed_ += kSpeedOfPipe;
  spawn_point_ -= (float) kSpeedOfPipe;
}
const int &Pipe::GetPipeFramesPassed() const {
  return frames_passed_;
}
const float &Pipe::GetSpawnPoint() const {
  return spawn_point_;
}
const float &Pipe::GetWidth() const {
  return width_;
}

}  // namespace flappybird