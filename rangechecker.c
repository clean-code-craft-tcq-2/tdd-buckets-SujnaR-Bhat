#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include "rangeChecker.h"
int *ConvertedDigitalArray;

// Convert Analog to Digital
int* ConvertA2D(int *Readings, int NoOfSamples)
{
    ConvertedDigitalArray = (int*)calloc(NoOfSamples, sizeof(int));
    for(int i=0;i<NoOfSamples;i++)
    {
         if (Readings[i] >4094)
         {
             Readings[i] = 0 ; //assume the invalid sample as 0
         }    
        ConvertedDigitalArray[i] = (10* Readings[i] )/ 4094;
        ConvertedDigitalArray[i] = round(ConvertedDigitalArray[i]);
    }
    return ConvertedDigitalArray;
}

// Sorting the input samples
int CompareInputs (const void * firstInput, const void * secondInput) 
{
    return ( *(int*)firstInput - *(int*)secondInput );
}


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
