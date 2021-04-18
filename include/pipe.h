#pragma once

#include "cinder/gl/gl.h"

namespace flappybird {

using glm::vec2;

class Pipe {
 public:

  /**
   * Constructor for initializing a Pipe object.
   * @param width of the pipe.
   * @param window_size used to spawn pipe.
   * @param margin used to spawn pipe.
   */
  Pipe(const float &width, const float &window_size, const float &margin);

  /**
   * Displays the pipe in its current positions.
   */
  void Draw();

  /**
   * Updates the position of the pipe.
   */
  void AdvanceOneFrame();

  /**
   * Keeps count of how much the pipe has traveled across the window.
   * @return a count.
   */
  const int &GetPipeFramesPassed() const;
  
  const float &GetSpawnPoint() const;
  const float &GetWidth() const;

 private:
  float width_;
  float spawn_point_;
  float window_size_;

  int frames_passed_ = 0;
  
  int kSpeedOfPipe = 2;
  std::string kColorOfPipe = "green";

};

}  // namespace flappybird