#include "engine.h"

namespace flappybird {

Engine::Engine(const int &window_size, const ci::gl::Texture2dRef &bird_image, const int &margin) {
  window_size_ = window_size;
  texture_ = bird_image;
  margin_ = margin;
  bird_ = Bird(window_size, bird_image, kBirdSpawnPosition);
  pipes_.emplace_back((float) kPipeWidth, (float) window_size, (float) margin_);
  
  UpdateEngine();
}

void Engine::DrawEngine() {

  for (Pipe &pipe : pipes_) {
    pipe.Draw();
  }

  bird_.Draw();

}

void Engine::UpdateEngine() {
  bird_.UpdateBird();

  if (HasCollided()) {
    has_hit_pipe_ = true;
    if (bird_.GetPosition().y == (float) window_size_) {
      bird_ = Bird(window_size_, texture_, kBirdSpawnPosition);
      pipes_.clear();
      has_hit_pipe_ = false;
      CreateNewPipe();
    }

  } else if (!has_hit_pipe_) {
    for (Pipe &pipe : pipes_) {
      pipe.AdvanceOneFrame();
    }

    frames_passed_++;

    if (frames_passed_ == kMaxFrames) {
      CreateNewPipe();
    }
    ErasePastPipes();
  }

}

bool Engine::HasCollided() {
  if (bird_.GetPosition().y + bird_.GetRadius() >= (float) window_size_) {
    return true;
  }

  for (Pipe pipe : pipes_) {
    if (bird_.GetBody().intersects(pipe.GetTopPipe()) || bird_.GetBody().intersects(pipe.GetBottomPipe())
        || bird_.GetPosition().x + bird_.GetRadius() == pipe.GetBottomPipe().getX1() && bird_.GetPosition().y < 0) {
      return true;
    }
  }
  return false;
}

void Engine::ErasePastPipes() {
  for (size_t pipe = 0; pipe < pipes_.size(); pipe++) {
    if (pipes_[pipe].GetPipeFramesPassed() > margin_ + window_size_ + kPipeWidth) {
      pipes_.erase(pipes_.begin());
    }
  }
}

void Engine::CreateNewPipe() {
  frames_passed_ = 0;
  pipes_.emplace_back((float) kPipeWidth, (float) window_size_, (float) margin_);
}

void Engine::ChangeBirdPhysics() {
  bird_.ChangeBirdOnSpace();
}

Bird &Engine::GetBird() {
  return bird_;
}

const bool &Engine::GetHasHitPipe() const {
  return has_hit_pipe_;
}
const vector<Pipe> &Engine::GetPipes() const {
  return pipes_;
}

}