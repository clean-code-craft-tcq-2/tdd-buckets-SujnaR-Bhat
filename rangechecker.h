typedef struct ReadingRange {
    int rangeStart;
    int rangeEnd;
    int numberOfReadings;
} ReadingRange;

typedef struct ReadingRangeList {
    ReadingRange *readingRanges;
    int totalReadingRanges;
} ReadingRangeList;

ReadingRangeList getReadingRangeList(int *readingsArray, int size);
int *sort(int array, int size);
