#include "pipe.h"

namespace flappybird {

using glm::vec2;

Pipe::Pipe(const float& width, const float& window_size) {
  width_ = width;
  window_size_ = window_size;
}

void Pipe::Display() const {
  // This function has a lot of magic numbers; be sure to design your code in a way that avoids this.
  ci::gl::color(ci::Color("green"));
  ci::gl::drawSolidRect(ci::Rectf(vec2(100, 0), vec2(100- width_, window_size_)));
}

void Pipe::AdvanceOneFrame() {
}

}  // namespace flappybird