
#include "bird_simulation_app.h"
#include "cinder/ImageIo.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::setup() {
  pipes_.emplace_back((float) kPipeWidth, (float) kWindowSize, (float) kMargin);
  texture_ = ci::gl::Texture2d::create(ci::loadImage(loadAsset("sunrise.jpg")));
}

void FlappyBirdApp::draw() {
//  ci::Color background_color(kBackGroundColor.c_str());
//  ci::gl::clear(background_color);
  ci::gl::clear();
  ci::gl::color(1,1,1);
  ci::gl::draw(texture_);

  bird_.Draw();
  
  for (Pipe &pipe : pipes_) {
    pipe.Draw();
  }
}

void FlappyBirdApp::update() {
  frames_passed_++;

  for (Pipe &pipe : pipes_) {
    pipe.AdvanceOneFrame();
  }

  if (frames_passed_ == kMaxFrames) {
    frames_passed_ = 0;
    pipes_.emplace_back((float) kPipeWidth, (float) kWindowSize, (float) kMargin);
  }
  bird_.UpdateBird();
  ErasePastPipes();
}

void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
  switch ((event.getCode())) {
    case ci::app::KeyEvent::KEY_SPACE:bird_.ChangeBirdOnSpace();
      break;
  }
}

void FlappyBirdApp::ErasePastPipes() {
  for (size_t pipe = 0; pipe < pipes_.size(); pipe++) {
    if (pipes_[pipe].GetPipeFramesPassed() > kMargin + kWindowSize + kPipeWidth) {
      pipes_.erase(pipes_.begin());
    }
  }
}

// Make another class (some type of container class) that passes in bird and a pipe to compare if bird makes contact with pipe
// Store boolean in a private variable and ues getter to call in this class?

}  // namespace flappybird 