#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * selection_sort - Function of the selection sort
 * @array: Pointer of the array
 * @size: Size of the array.
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;

    if (!array || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            int temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;

            print_array(array, size);
        }
    }
}