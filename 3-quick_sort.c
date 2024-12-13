#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer to swap
 * @b: second integer to swap
 */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * part - find partition index
 * @array: array of integers
 * @first: first integer to sort
 * @last: last integer to sort
 */

int part(int *array, size_t size, int first, int last)
{
    int *p, i, j;
    p = array + last;
    for (i = j = first; j < last; j++)
    {
        if (array[j] < *p)
        {
            if (i < j)
            {
                swap(array + j, array + i);
                print_array(array, size);
            }
            i++;
        }
    }
    if (array[i] > *p)
    {
    swap(array + i, p);
    print_array(array, size);
    }
    return (i);
}

/**
 * sort - sorts array with part
 * @array: array of integers
 * @first: first integer to sort
 * @last: last integer to sort
 */

void sort(int *array, size_t size, int first, int last)
{
    int partindex;
    if (first < last)
    {
        partindex = part(array, size, first, last);
        sort(array, size, first, partindex - 1);
        sort(array, size, partindex + 1, last);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order using the quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    sort(array, size, 0, size - 1);
}