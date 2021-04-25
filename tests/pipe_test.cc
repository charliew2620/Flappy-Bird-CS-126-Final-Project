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

TEST_CASE("Tests to see if bottom and top pipe are created") {
  REQUIRE(pipe.GetBottomPipe().getX1() == 990.0f);
  REQUIRE(pipe.GetTopPipe().getX1() == 990.0f);
}

TEST_CASE("Tests to see if created pipe lengths isn't too long") {
  flappybird::Pipe pipe_test;
  for (int i = 0; i < 20; i++) {
    pipe_test = flappybird::Pipe(80, 900, 90);
    REQUIRE(pipe_test.GetTopPipe().getY2() <= 645);
    REQUIRE(pipe_test.GetBottomPipe().getY1() == pipe_test.GetTopPipe().getY2() + 175);
  }
}

TEST_CASE("Tests AdvanceOneFrame method") {
  flappybird::Pipe pipe1(80, 900, 90);
  pipe1.AdvanceOneFrame();

  SECTION("Tests if whole pipe has moved") {
    REQUIRE(pipe1.GetSpawnPoint() == 988.0f);
  }

  SECTION("Tests frames pipe has passed") {
    REQUIRE(pipe1.GetPipeFramesPassed() == 2);
  }
  
  SECTION("Tests if bottom and top pipe has moved") {
    REQUIRE(pipe1.GetTopPipe().getX1() == 988.0f);
    REQUIRE(pipe1.GetBottomPipe().getX1() == 988.0f);
  }
}
