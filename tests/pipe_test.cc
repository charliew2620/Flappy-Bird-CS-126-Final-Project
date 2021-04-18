#include <catch2/catch.hpp>

#include <pipe.h>

flappybird::Pipe pipe(80, 900, 90);

TEST_CASE("Tests initial position of pipe") {
  REQUIRE(pipe.GetSpawnPoint() == 990);
}

TEST_CASE("Tests width of pipe") {
  REQUIRE(pipe.GetWidth() == 80);
}

TEST_CASE("Tests initial frames passed") {
  REQUIRE(pipe.GetPipeFramesPassed() == 0);
}
