#include "engine.h"

namespace flappybird {

Engine::Engine(const Bird& bird, const vector<Pipe>& pipes, const int window_size) {
  bird_ = bird;
  pipes_ = pipes;
  window_size_ = window_size;
}
bool Engine::HasCollided() {
  if (bird_.GetPosition().y + 2 * bird_.GetRadius() >= (float) window_size_) {
    return true;
  }
  return false;
}

}