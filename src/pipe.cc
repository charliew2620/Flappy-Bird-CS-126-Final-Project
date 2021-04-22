#include "pipe.h"

namespace flappybird {

using glm::vec2;

Pipe::Pipe(const float &width, const float &window_size, const float &margin, const int &pipe_speed) {
  width_ = width;
  window_size_ = window_size;
  pipe_speed_ = pipe_speed;
  spawn_point_ = window_size + margin;
  top_pipe_length_ = (float) GivePipeRandomLength();

  SetPositionsOfPipes();
}

void Pipe::Draw() {
  ci::gl::color(kRed / kRed, kGreen / kRed, kBlue / kRed);
  ci::gl::drawSolidRect(top_pipe_);
  ci::gl::drawSolidRect(bottom_pipe_);
}

void Pipe::AdvanceOneFrame() {
  SetPositionsOfPipes();
  frames_passed_ += pipe_speed_;
  spawn_point_ -= (float) pipe_speed_;
}

void Pipe::SetPositionsOfPipes() {
  top_pipe_ = ci::Rectf(vec2(spawn_point_, 0), vec2(spawn_point_ + width_, top_pipe_length_));
  bottom_pipe_ = ci::Rectf(vec2(spawn_point_, top_pipe_length_ + kLengthBetweenPipes),
                           vec2(spawn_point_ + width_, window_size_));
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
int Pipe::GivePipeRandomLength() {
  return rand() % (int) (window_size_ - 80 - kLengthBetweenPipes);
}
const ci::Rectf &Pipe::GetTopPipe() const {
  return top_pipe_;
}
const ci::Rectf &Pipe::GetBottomPipe() const {
  return bottom_pipe_;
}

}  // namespace flappybird