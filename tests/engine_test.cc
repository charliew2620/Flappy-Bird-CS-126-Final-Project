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