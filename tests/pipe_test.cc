#include <catch2/catch.hpp>

#include <pipe.h>

using flappybird::Pipe;

TEST_CASE("Placeholder test") {
Pipe pipe;
pipe.AdvanceOneFrame();
REQUIRE(1 > 0);
}