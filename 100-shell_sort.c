#include "sort.h"

/**
 * swap - swap two elements in the array
 * @num_1: the first element
 * @num_2: the second element
*/

void swap(int *num_1, int *num_2)
{
	int temp = *num_1;
	*num_1 = *num_2;
	*num_2 = temp;
}

/**
 * shell_sort - sort the array by using
 * the shell sort alogrithm
 * @array: hold the array elements
 * @size: the size of the array
*/

void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (!array || size < 2)
		return;

	for (interval = 1; interval < size / 3;)
		interval = interval * 3 + 1;
	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; i >= interval && array[j - interval] > array[j]; j -= interval)
			{
				swap(&array[j - interval], &array[j]);
			}
		}
		print_array(array, size);
	}
}
