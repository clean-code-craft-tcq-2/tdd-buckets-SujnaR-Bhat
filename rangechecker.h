typedef struct ReadingRange {
    int rangeStart;
    int rangeEnd;
    int numberOfReadings;
} ReadingRange;

typedef struct ReadingRangeList {
    ReadingRange *ReadingsRanges ;
    int totalReadingRanges;
} ReadingsRangeList ;

ReadingsRangeList GetListofReadingsRange(int *ArrayofReadings, int size);
int *sort(int array, int size);
