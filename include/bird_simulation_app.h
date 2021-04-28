#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "engine.h"

namespace flappybird {

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
  const int kWindowSize = 870;
  const int kMargin = 100;

  Engine engine_;

  ci::gl::Texture2dRef texture_;
  ci::gl::Texture2dRef kBirdImage = ci::gl::Texture2d::create(ci::loadImage(loadAsset("flappybird.png")));
  std::string kBackgroundImage = "sunrise.png";
};

}  // namespace flappybird