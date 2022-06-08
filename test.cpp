#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

TEST_CASE("detect range of input array of integers") {
   REQUIRE(inferBreach(3,5) == 4);
}
