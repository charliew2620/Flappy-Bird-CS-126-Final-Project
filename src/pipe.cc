#include "pipe.h"

namespace flappybird {

using glm::vec2;

Pipe::Pipe(const float &width, const float &window_size, const float &margin) {
  width_ = width;
  window_size_ = window_size;
  spawn_point_ = window_size + margin;
  top_pipe_length_ = (float) GiveTopPipeRandomLength();
  pipe_passed_ = false;

  SetPositionsOfPipes();
}

void Pipe::Draw() {
  ci::gl::color(kRed / kRed, kGreen / kRed, kBlue / kRed);
  ci::gl::drawSolidRect(top_pipe_);
  ci::gl::drawSolidRect(bottom_pipe_);
}

void Pipe::AdvanceOneFrame() {
  frames_passed_ += kPipeVelocity;
  spawn_point_ -= (float) kPipeVelocity;
  SetPositionsOfPipes();
}

void Pipe::SetPositionsOfPipes() {
  top_pipe_ = ci::Rectf(vec2(spawn_point_, 0), vec2(spawn_point_ + width_, top_pipe_length_));
  bottom_pipe_ = ci::Rectf(vec2(spawn_point_, top_pipe_length_ + kLengthBetweenPipes),
                           vec2(spawn_point_ + width_, window_size_));
  space_between_pipes_ = ci::Rectf(vec2(spawn_point_, top_pipe_length_), vec2(spawn_point_ + width_, top_pipe_length_ + kLengthBetweenPipes));
}

void Pipe::PipeHasBeenPassed() {
  pipe_passed_ = true;
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
int Pipe::GiveTopPipeRandomLength() {
  return rand() % (int) (window_size_ - kMinPipeLength - kLengthBetweenPipes);
}
const ci::Rectf &Pipe::GetTopPipe() const {
  return top_pipe_;
}
const ci::Rectf &Pipe::GetBottomPipe() const {
  return bottom_pipe_;
}
const ci::Rectf &Pipe::GetSpaceBetweenPipes() const {
  return space_between_pipes_;
}
const bool &Pipe::HasPipeBeenPassed() const {
  return pipe_passed_;
}
}  // namespace flappybird