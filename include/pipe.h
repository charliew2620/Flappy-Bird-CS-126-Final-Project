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
   * Default constructor
   */
  Pipe() = default;

  /**
   * Displays the pipe in its current positions.
   */
  void Draw();

  /**
   * Updates the position of the pipe.
   */
  void AdvanceOneFrame();
  
  /**
   * Called when pipe has been passed by bird.
   */
  void PipeHasBeenPassed();

  /**
   * Keeps count of how much the pipe has traveled across the window.
   * @return a count.
   */
  const int &GetPipeFramesPassed() const;

  // getters
  const float &GetSpawnPoint() const;
  const float &GetWidth() const;
  const ci::Rectf &GetTopPipe() const;
  const ci::Rectf &GetBottomPipe() const;
  const ci::Rectf &GetSpaceBetweenPipes() const;
  const bool &HasPipeBeenPassed() const;

 private:
  float width_;
  float spawn_point_;
  float window_size_;

  float kRed = 202.0f;
  float kGreen = 83.0f;
  float kBlue = 16.0f;

  float kLengthBetweenPipes = 175;
  float top_pipe_length_;
  float kMinPipeLength = 80;

  int frames_passed_ = 0;
  int kPipeVelocity = 2;

  ci::Rectf top_pipe_;
  ci::Rectf bottom_pipe_;
  ci::Rectf space_between_pipes_;
  
  bool pipe_passed_;

  /**
   * Gives top pipe random length.
   * @return the length of the pipe.
   */
  int GiveTopPipeRandomLength();

  /**
   * Sets the position of the bottom and top pipes.
   */
  void SetPositionsOfPipes();
};

}  // namespace flappybird