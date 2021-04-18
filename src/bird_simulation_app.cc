
#include "bird_simulation_app.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::draw() {
  ci::Color background_color("aqua");
  ci::gl::clear(background_color);

  //pipe_.Display();
  bird_.Draw();
}

void FlappyBirdApp::update() {
  bird_.UpdateBird(); 
  //pipe_.AdvanceOneFrame();
}

void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
  switch ((event.getCode())) {
    case ci::app::KeyEvent::KEY_SPACE:
      bird_.ChangeBirdOnSpace();
      break;
  }
}

}  // namespace flappybird 