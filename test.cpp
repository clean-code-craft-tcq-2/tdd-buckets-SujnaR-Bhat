#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "rangeChecker.h"
#include <string.h>

TEST_CASE("Check the range and total number of readings lying in each range") {
  int arr[5] = {1, 3, 2, 12, 11};
  ReadingRange expectedReadingRange[2] = {{1, 3, 3}, {11, 12, 2}};
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
