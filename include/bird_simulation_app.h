#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pipe.h"

namespace flappybird {

/**
 * An app for visualizing the behavior of an ideal gas.
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
   * Calls PopulateContainer() to populate container with particles.
   */
  //void setup() override;

  /**
   * Draws the background of the window.
   */
  void draw() override;

  /**
   * Calls AdvanceOneFrame() method and updates particles' positions.
   */
  void update() override;

 private:
  Pipe pipe_;
};

}  // namespace flappybird