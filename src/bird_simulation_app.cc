
#include "bird_simulation_app.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::setup() {
  engine_ = Engine(kWindowSize, kBirdImage, kMargin);

  ci::gl::Texture2d::Format fmt;

  fmt.setWrap(GL_FILL, GL_FILL);
  
  texture_ = ci::gl::Texture2d::create(ci::loadImage(loadAsset(kBackgroundImage)), fmt);
}

void FlappyBirdApp::draw() {
  ci::gl::clear();
  ci::gl::color(1, 1, 1);
  ci::gl::draw(texture_);
  
  engine_.DrawEngine();
}

void FlappyBirdApp::update() {
  engine_.UpdateEngine();
}


void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
  switch ((event.getCode())) {
    case ci::app::KeyEvent::KEY_SPACE:
      if (!engine_.HasCollided() && !engine_.GetHasHitPipe()) {
        engine_.ChangeBirdPhysics();
      }
      break;
  }
}
}  // namespace flappybird 