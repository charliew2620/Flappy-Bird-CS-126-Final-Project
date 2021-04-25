#include <catch2/catch.hpp>
#include <bird.h>

using glm::vec2;

ci::gl::Texture2dRef bird_image;
flappybird::Bird bird(870, bird_image, vec2(300, 450));

TEST_CASE("Tests spawn position") {
  REQUIRE(bird.GetPosition() == vec2(300, 450));
}

TEST_CASE("Tests radius") {
  REQUIRE(bird.GetRadius() == 20);
}
TEST_CASE("Tests initial velocity") {
  REQUIRE(bird.GetVelocity() == 0);
}

TEST_CASE("Tests initial acceleration") {
  REQUIRE(bird.GetAcceleration() == 0);
}

TEST_CASE("Tests color") {
  REQUIRE(bird.GetColor() == "yellow");
}

TEST_CASE("Tests body") {
  flappybird::Bird bird1(870, bird_image, vec2(300, 450));
  REQUIRE(bird1.GetBody().getX1() == 280.0f);
  REQUIRE(bird1.GetBody().getX2() == 320.0f);
  REQUIRE(bird1.GetBody().getY1() == 430.0f);
  REQUIRE(bird1.GetBody().getY2() == 470.0f);
}

TEST_CASE("Tests Update method") {
  SECTION("Tests to see if bird falls correctly after one frame") {
    flappybird::Bird bird1(870, bird_image, vec2(300, 450));
    bird1.UpdateBird();
    REQUIRE(bird1.GetPosition() == vec2(300, 450.4));
    REQUIRE(bird1.GetVelocity() == 0.4f);
    REQUIRE(bird1.GetAcceleration() == 0.4f);
  }
  
  SECTION("Tests bird when it hits the ground") {
    flappybird::Bird bird1(870, bird_image, vec2(300, 870));
    bird1.UpdateBird();
    REQUIRE(bird1.GetPosition() == vec2(300, 870));
    REQUIRE(bird1.GetVelocity() == 0);
    REQUIRE(bird1.GetAcceleration() == 0);
  }
}

TEST_CASE("Tests ChangeBirdOnSpace method") {
  flappybird::Bird bird1(870, bird_image, vec2(300, 450));
  bird1.ChangeBirdOnSpace();
  REQUIRE(bird1.GetPosition() == vec2(300, 442));
  REQUIRE(bird1.GetVelocity() == -8.0f);
  REQUIRE(bird1.GetAcceleration() == 0);
}


