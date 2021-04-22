#pragma once

#include "cinder/gl/gl.h"
#include "pipe.h"
#include "bird.h"

namespace flappybird {

class Engine {
 public:
  
  Engine(const Bird &bird, const Pipe &pipe, const int &window_size);
  
 private:
  
  Bird bird_;
  Pipe pipe_;
  int window_size_;
};
}