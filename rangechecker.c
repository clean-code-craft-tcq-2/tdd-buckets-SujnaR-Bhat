#include <stdio.h>
#include <cstdlib>
#include "rangeChecker.h"

int *sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}

ReadingsRangeList GetListofReadingsRange(int *ArrayofReadings, int size)
{
    int *sortedArray = sort(ArrayofReadings, size);
    ReadingRange *ReadingsRanges = (ReadingRange *)malloc(size * sizeof(ReadingRange));
   int start = sortedArray[0], end = sortedArray[0], count = 0, rangeIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (sortedArray[i] == start || sortedArray[i] == end + 1)
        {
            count++;
            end = sortedArray[i];
        }
        else
        {
            ReadingsRanges[rangeIndex] = {start, end, count};
            rangeIndex++;
            count = 1;
            start = sortedArray[i];
            end = start;
        }
    }
    ReadingsRanges[rangeIndex] = {start, end, count};
    ReadingsRangeList ListofReadingsRange = {ReadingsRanges, rangeIndex + 1};
    for (int i = 0; i < ListofReadingsRange.totalReadingRanges; i++)
    {
        printf("%d-%d, %d\n", ReadingsRanges[i].rangeStart, ReadingsRanges[i].rangeEnd, ReadingsRanges[i].numberOfReadings);
    }
    return ListofReadingsRange;
}
