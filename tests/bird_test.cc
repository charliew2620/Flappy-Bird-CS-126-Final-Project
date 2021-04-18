#include <catch2/catch.hpp>
#include <bird.h>

using glm::vec2;

flappybird::Bird bird;

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


