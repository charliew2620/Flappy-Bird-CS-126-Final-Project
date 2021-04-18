
#include "bird_simulation_app.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::setup() {
  pipes_.emplace_back(kPipeWidth, (float) kWindowSize, (float) kMargin);
}

void FlappyBirdApp::draw() {
  ci::Color background_color("aqua");
  ci::gl::clear(background_color);
  bird_.Draw();
  
  for (Pipe& pipe : pipes_) {
    pipe.Draw();
  }
}

void FlappyBirdApp::update() {
  frames_passed_++;

  for (Pipe& pipe : pipes_) {
    pipe.AdvanceOneFrame();
  }
  
  if (frames_passed_ == 225) {
    frames_passed_ = 0;
    pipes_.emplace_back(kPipeWidth, (float) kWindowSize, (float) kMargin);
  }
  bird_.UpdateBird();
  ErasePastPipes();
}

void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
  switch ((event.getCode())) {
    case ci::app::KeyEvent::KEY_SPACE:
      bird_.ChangeBirdOnSpace();
      break;
  }
}
void FlappyBirdApp::ErasePastPipes() {
  for (int pipe = 0; pipe < pipes_.size(); pipe++) {
    if (pipes_.at(pipe).GetPipeFramesPassed() > kMargin + kWindowSize) {
      pipes_.erase(pipes_.begin() + pipe);
    }
  }
}

}  // namespace flappybird 