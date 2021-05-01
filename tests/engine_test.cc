#include <catch2/catch.hpp>

#include <engine.h>
#include <bird.h>
#include <pipe.h>

using glm::vec2;

TEST_CASE("Tests HasCollided method") {
  SECTION("Tests that bird has not hit ground or pipes") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    engine.GetBird() = flappybird::Bird(870, bird_image, vec2(300, 450));
    REQUIRE_FALSE(engine.HasCollided());
  }

  SECTION("Bird hits the ground") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    engine.GetBird() = flappybird::Bird(870, bird_image, vec2(300, 870));
    REQUIRE(engine.HasCollided());
  }

  SECTION("Bird hits top pipe") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    engine.GetBird() = flappybird::Bird(870, bird_image, vec2(970, 0));
    REQUIRE(engine.HasCollided());
  }

  SECTION("Bird hits bottom pipe") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    engine.GetBird() = flappybird::Bird(870, bird_image, vec2(970, 790));
    REQUIRE(engine.HasCollided());
  }
}

TEST_CASE("Tests TrackScore method") {
  ci::gl::Texture2dRef bird_image;
  SECTION("Checks if score is 0 at start of game") {
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    REQUIRE(engine.GetScore() == 0);
  }SECTION("Checks if score increases if bird passes pipe") {
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    engine.GetBird() = flappybird::Bird(870,
                                        bird_image,
                                        vec2(engine.GetPipes()[0].GetTopPipe().x1,
                                             engine.GetPipes()[0].GetTopPipe().y2 + 100));
    engine.UpdateEngine();
    REQUIRE(engine.GetScore() == 1);
  }SECTION("Checks if score resets from 1 to 0 after bird dies") {
    flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
    engine.GetBird() = flappybird::Bird(870,
                                        bird_image,
                                        vec2(engine.GetPipes()[0].GetTopPipe().x1,
                                             engine.GetPipes()[0].GetTopPipe().y2 + 100));
    engine.UpdateEngine();
    REQUIRE(engine.GetScore() == 1);
    engine.GetBird() = flappybird::Bird(870,
                                        bird_image,
                                        vec2(engine.GetPipes()[0].GetTopPipe().x1,
                                             engine.GetPipes()[0].GetBottomPipe().y2));
    engine.UpdateEngine();
    REQUIRE(engine.GetScore() == 0);
  }
}

TEST_CASE("Tests if new pipe is being created every 225 frames") {
  ci::gl::Texture2dRef bird_image;
  flappybird::Engine engine = flappybird::Engine(870, bird_image, 100);
  for (int i = 0; i < 225; i++) {
    engine.UpdateEngine();
    // To keep bird from falling and resetting game
    engine.GetBird() = flappybird::Bird(870,
                                        bird_image,
                                        vec2(engine.GetPipes()[0].GetTopPipe().x1,
                                             engine.GetPipes()[0].GetTopPipe().y2 + 100));
  }
  REQUIRE(engine.GetPipes().size() == 2);
}