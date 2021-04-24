
#include "bird_simulation_app.h"

namespace flappybird {

FlappyBirdApp::FlappyBirdApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void FlappyBirdApp::setup() {
  bird_ = Bird(kWindowSize, kBirdImage);
  pipes_.emplace_back((float) kPipeWidth, (float) kWindowSize, (float) kMargin);
  engine_ = Engine(bird_, pipes_, kWindowSize);

  ci::gl::Texture2d::Format fmt;

  fmt.setWrap(GL_FILL, GL_FILL);
  
  texture_ = ci::gl::Texture2d::create(ci::loadImage(loadAsset("sunrise.png")), fmt);
}

void FlappyBirdApp::draw() {
  ci::gl::clear();
  ci::gl::color(1, 1, 1);
  ci::gl::draw(texture_);

  for (Pipe &pipe : pipes_) {
    pipe.Draw();
  }

  bird_.Draw();
}

void FlappyBirdApp::update() {
  bird_.UpdateBird();

  // Checks collision
  if (engine_.HasCollided()) {
    has_hit_pipe_ = true;
    if (bird_.GetPosition().y == (float) kWindowSize) {
      bird_ = Bird(kWindowSize, kBirdImage);
      pipes_.clear();
      has_hit_pipe_ = false;
      CreateNewPipe();
    }

  } else if (!has_hit_pipe_){
    for (Pipe &pipe : pipes_) {
      pipe.AdvanceOneFrame();
    }

    frames_passed_++;

    if (frames_passed_ == kMaxFrames) {
      CreateNewPipe();
    }
    ErasePastPipes();
  }
  engine_ = Engine(bird_, pipes_, kWindowSize);
}

void FlappyBirdApp::CreateNewPipe() {
  frames_passed_ = 0;
  pipes_.emplace_back((float) kPipeWidth, (float) kWindowSize, (float) kMargin);
  engine_ = Engine(bird_, pipes_, kWindowSize);
}

void FlappyBirdApp::ErasePastPipes() {
  for (size_t pipe = 0; pipe < pipes_.size(); pipe++) {
    if (pipes_[pipe].GetPipeFramesPassed() > kMargin + kWindowSize + kPipeWidth) {
      pipes_.erase(pipes_.begin());
    }
  }
}

void FlappyBirdApp::keyDown(ci::app::KeyEvent event) {
  switch ((event.getCode())) {
    case ci::app::KeyEvent::KEY_SPACE:
      if (!engine_.HasCollided() && !has_hit_pipe_) {
        bird_.ChangeBirdOnSpace();
      }
      break;
  }
}

// Make another class (some type of container class) that passes in bird and a pipe to compare if bird makes contact with pipe
// Store boolean in a private variable and ues getter to call in this class?
//store and draw score

}  // namespace flappybird 