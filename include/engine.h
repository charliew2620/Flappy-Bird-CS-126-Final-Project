#pragma once

#include "cinder/gl/gl.h"
#include "pipe.h"
#include "bird.h"

namespace flappybird {
using std::vector;

class Engine {
 public:

  Engine(const int &window_size, const ci::gl::Texture2dRef &bird_image, const int &margin);

  Engine() = default;

  bool HasCollided();

  void UpdateEngine();

  void DrawEngine();

  // Not const for purposes of testing
  Bird &GetBird();
  
  const vector<Pipe> &GetPipes() const; 

  const bool &GetHasHitPipe() const;

  void ChangeBirdPhysics();

 private:

  Bird bird_;
  vector<Pipe> pipes_;
  int window_size_;

  int margin_;

  vec2 kBirdSpawnPosition = vec2(300, 450);

  int frames_passed_ = 0;
  int kPipeWidth = 80;
  int kMaxFrames = 225;

  ci::gl::Texture2dRef texture_;

  bool has_hit_pipe_ = false;
  
  int score_;

  double kXScorePositionRatio = 2.0;
  double kYScorePositionRatio = 8.7;
  ci::Color kScoreColor = "white";
  std::string kScoreFont = "Impact";
  float kScoreFontSize = 60;

  /**
   * Erases pipes that have gone past the window.
   */
  void ErasePastPipes();

  /**
   * Creates a new Pipe object.
   */
  void CreateNewPipe();
  
  void TrackScore();
};
} // namespace flappybird