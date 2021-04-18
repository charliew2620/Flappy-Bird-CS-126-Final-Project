#pragma once

#include "cinder/gl/gl.h"


namespace flappybird {

using glm::vec2;
/**
 * The container in which all of the gas particles are contained. This class
 * stores all of the particles and updates them on each frame of the simulation.
 */
class Pipe {
 public:
  /**
   * TODO: Add more parameters to this constructor, and add documentation.
   */
  Pipe(const float& width, const float& window_size);

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  /**
   * Updates the positions and velocities of all particles (based on the rules
   * described in the assignment documentation).
   */
  void AdvanceOneFrame();

 private:
  float width_;
  float window_size_;
  
  
};

}  // namespace flappybird