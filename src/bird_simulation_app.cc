
#include "bird_simulation_app.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::draw() {
  ci::Color background_color("aqua");
  ci::gl::clear(background_color);
  bird_.Draw();
  
  for (Pipe pipe : pipes_) {
    pipe.Display();
  }
}

void FlappyBirdApp::update() {
  frames_passed_++;
  
  if (frames_passed_ == 225) {
    frames_passed_ = 0;
    pipes_.emplace_back(kPipeWidth, float( kWindowSize + kMargin));
  }
  bird_.UpdateBird();
  
  for (Pipe pipe : pipes_) {
    pipe.AdvanceOneFrame();
  }
}

void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
  switch ((event.getCode())) {
    case ci::app::KeyEvent::KEY_SPACE:
      bird_.ChangeBirdOnSpace();
      break;
  }
}

}  // namespace flappybird 