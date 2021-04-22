#pragma once

#include "cinder/gl/gl.h"
#include "pipe.h"
#include "bird.h"

namespace flappybird {
using std::vector;


class Engine {
 public:
  
  Engine(const Bird& bird, const vector<Pipe>& pipes, const int window_size);
  
  Engine() = default;
  
  bool HasCollided();
  
 private:
  
  Bird bird_;
  vector<Pipe> pipes_;
  int window_size_;
};
}