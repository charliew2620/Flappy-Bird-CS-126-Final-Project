
#include "bird_simulation_app.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  pipe_.Display();
}

void FlappyBirdApp::update() {
  pipe_.AdvanceOneFrame();
}

}  // namespace flappybird 