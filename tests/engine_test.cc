#include <catch2/catch.hpp>

#include <engine.h>
#include <bird.h>
#include <pipe.h>

using glm::vec2;
using std::vector;

TEST_CASE("Tests HasCollided method") {
  SECTION("Tests that bird has not hit ground or pipes") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Bird bird = flappybird::Bird(870, bird_image, vec2(300, 450));
    vector<flappybird::Pipe> pipes;
    pipes.emplace_back(80.0f, 870.0f, 100.0f);
    flappybird::Engine engine = flappybird::Engine(bird, pipes, 870);
    REQUIRE_FALSE(engine.HasCollided());
  }
  
  SECTION("Bird hits the ground") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Bird bird = flappybird::Bird(870, bird_image, vec2(300, 870));
    vector<flappybird::Pipe> pipes;
    pipes.emplace_back(80.0f, 870.0f, 100.0f);
    flappybird::Engine engine = flappybird::Engine(bird, pipes, 870);
    REQUIRE(engine.HasCollided());
  }

  SECTION("Bird hits top pipe") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Bird bird = flappybird::Bird(870, bird_image, vec2(970, 0));
    vector<flappybird::Pipe> pipes;
    pipes.emplace_back(80.0f, 870.0f, 100.0f);
    flappybird::Engine engine = flappybird::Engine(bird, pipes, 870);
    REQUIRE(engine.HasCollided());
  }

  SECTION("Bird hits bottom pipe") {
    ci::gl::Texture2dRef bird_image;
    flappybird::Bird bird = flappybird::Bird(870, bird_image, vec2(970, 790));
    vector<flappybird::Pipe> pipes;
    pipes.emplace_back(80.0f, 870.0f, 100.0f);
    flappybird::Engine engine = flappybird::Engine(bird, pipes, 870);
    REQUIRE(engine.HasCollided());
  }
}