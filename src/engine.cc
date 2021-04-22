#include "engine.h"

namespace flappybird {

Engine::Engine(const Bird &bird, const Pipe &pipe, const int &window_size) {
  bird_ = bird;
  pipe_ = pipe;
  window_size_ = window_size;
}


}