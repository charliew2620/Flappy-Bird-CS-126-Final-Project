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
  const int kWindowSize = 900;
  const int kMargin = 90;

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
  Bird bird_;
  vector<Pipe> pipes_;

  int frames_passed_ = 0;
  int kPipeWidth = 80;

  /**
   * Erases pipes that have gone past the window.
   */
  void ErasePastPipes();
};

}  // namespace flappybird