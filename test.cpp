#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "rangeChecker.h"
#include <string.h>

TEST_CASE("Check the range and total number of readings lying in each range") {
  int arr[5] = {7, 8, 9, 15, 14};
  ReadingRange expectedReadingRange[2] = {{7, 9, 9}, {15, 14, 5}};
  ReadingRangeList expectedReadingRangeList = {expectedReadingRange, 2};
  ReadingRangeList actualReadingRangeList = getReadingRangeList(arr, 5);
  ReadingRange *actualReadingRange = actualReadingRangeList.readingRanges;
  for (int i = 0; i < expectedReadingRangeList.totalReadingRanges; i++)
  {
      REQUIRE(actualReadingRange[i].rangeStart == expectedReadingRange[i].rangeStart);
      REQUIRE(actualReadingRange[i].rangeEnd == expectedReadingRange[i].rangeEnd);
      REQUIRE(actualReadingRange[i].numberOfReadings == expectedReadingRange[i].numberOfReadings);
  }
}
