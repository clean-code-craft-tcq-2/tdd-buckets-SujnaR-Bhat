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

ReadingRangeList getReadingRangeList(int *ArrayofReadings, int size)
{
    int *sortedArray = sort(ArrayofReadings, size);
    ReadingRange *readingRanges = (ReadingRange *)malloc(size * sizeof(ReadingRange));
    int start = sortedArray[0], end = sortedArray[0], count = 0, rangeIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (sortedArray[i] == start || sortedArray[i] == end + 1)
