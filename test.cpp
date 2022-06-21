#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "main.h"

TEST_CASE("detect set of values  from  specified range within input array of integers") {
   int sampleArray[] ={2,3, 3, 5, 4, 10, 11, 12};
   
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getNoOfRValuesInRange(sampleArray,startRangeValue,endRangeValue) == 5);
   
   startRangeValue = 10;
   endRangeValue = 12;
   REQUIRE(getNoOfRValuesInRange(sampleArray,startRangeValue,endRangeValue) == 3);
   
}
