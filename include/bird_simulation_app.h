#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pipe.h"
#include "bird.h"

namespace flappybird {

using std::vector;

/**
 * An app for visualizing the game of flappy bird.
 */
class FlappyBirdApp : public ci::app::App {

 public:
  /**
   * Sets window size.
   */
  FlappyBirdApp();

  /**
   * Spawns the first pipe.
   */
  void setup() override;

  /**
   * Draws the background of the window.
   */
  void draw() override;

  /**
   * Updates the bird's position as well as all pipes.
   */
  void update() override;

  /**
   * Allows bird to jump if space is pressed.
   * @param event detects if space has been pressed.
   */
  void keyDown(ci::app::KeyEvent event) override;

 private:
  const int kWindowSize = 850;
  const int kMargin = 90;
  
  Bird bird_;
  vector<Pipe> pipes_;

  int frames_passed_ = 0;
  int kPipeWidth = 80;
  int kMaxFrames = 225;
  std::string kBackGroundColor = "aqua";

  ci::gl::Texture2dRef texture_;

  /**
   * Erases pipes that have gone past the window.
   */
  void ErasePastPipes();
};

}  // namespace flappybird