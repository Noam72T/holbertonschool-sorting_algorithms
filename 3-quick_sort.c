#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer to swap
 * @b: Second integer to swap
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * part - Find partition index
 * @array: Array of integers
 * @size: Size of the array
 * @first: First integer to sort
 * @last: Last integer to sort
 *
 * Return: Index of the pivot
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
 * sort - Sorts array with part
 * @array: Array of integers
 * @size: Size of the array
 * @first: First integer to sort
 * @last: Last integer to sort
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
 * quick_sort - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
