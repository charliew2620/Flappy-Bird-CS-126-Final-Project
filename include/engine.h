#pragma once

#include "cinder/gl/gl.h"
#include "pipe.h"
#include "bird.h"

namespace flappybird {
using std::vector;

class Engine {
 public:

  /**
   * Constructor for creating an Engine object.
   * @param window_size window size of screen.
   * @param bird_image for drawing the bird.
   * @param margin to be used in calculations.
   */
  Engine(const int &window_size, const ci::gl::Texture2dRef &bird_image, const int &margin);

  Engine() = default;

  /**
   * Checks if bird has collided with ground or pipes.
   * @return true if collision happened.
   */
  bool HasCollided();

  /**
   * Updates variables of the engine object.
   */
  void UpdateEngine();

  /**
   * Draws objects of engine object.
   */
  void DrawEngine();

  /**
   * Used to change physics of bird when space is pressed.
   */
  void ChangeBirdPhysics();

  // Not const for purposes of testing
  Bird &GetBird();

  const vector<Pipe> &GetPipes() const;

  const bool &GetHasHitPipe() const;
  
  const int &GetScore() const;
  

 private:

  Bird bird_;
  vector<Pipe> pipes_;
  int window_size_;

  int margin_;

  vec2 kBirdSpawnPosition = vec2(375, 450);

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

  /**
   * Tracks the number of pipes bird has passed.
   */
  void TrackScore();
};
} // namespace flappybird