#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pipe.h"
#include "bird.h"

namespace flappybird {

using std::vector;

/**
 * An app for visualizing the behavior of an ideal gas.
 */
class FlappyBirdApp : public ci::app::App {
  const int kWindowSize = 900;
  const int kMargin = 80;

 public:
  /**
   * Sets window size.
   */
  FlappyBirdApp();

  /**
   * Calls PopulateContainer() to populate container with particles.
   */
  void setup() override;

  /**
   * Draws the background of the window.
   */
  void draw() override;

  /**
   * Calls AdvanceOneFrame() method and updates particles' positions.
   */
  void update() override;

  void keyDown(ci::app::KeyEvent event) override;

 private:
  Bird bird_;
  vector<Pipe> pipes_;
  
  int frames_passed_ = 0;
  float kPipeWidth = 75;
  
  void ErasePastPipes();
};

}  // namespace flappybird