#include "engine.h"

namespace flappybird {

Engine::Engine(const Bird &bird, const vector<Pipe> &pipes, const int window_size) {
  bird_ = bird;
  pipes_ = pipes;
  window_size_ = window_size;
}
bool Engine::HasCollided() {
  if (bird_.GetPosition().y + bird_.GetRadius() >= (float) window_size_) {
    return true;
  }

  for (Pipe pipe : pipes_) {
    if (bird_.GetBody().intersects(pipe.GetTopPipe()) || bird_.GetBody().intersects(pipe.GetBottomPipe())
        || bird_.GetPosition().x + bird_.GetRadius() == pipe.GetBottomPipe().getX1() && bird_.GetPosition().y < 0) {
      return true;
    }
  }
  return false;
}

}