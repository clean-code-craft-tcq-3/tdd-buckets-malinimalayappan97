#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

TEST_CASE("detect set of values  from  specified range within input array of integers") {
   int sampleArray[] ={3, 3, 5, 4, 10, 11, 12}
   int startRangeValue = 3;
   int endRangeValue = 5;
   REQUIRE(getRangeValues(sampleArray,startRangeValue,endRangeValue) == 4);
}
