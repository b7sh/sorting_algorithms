#include "sort.h"

/**
 * swap - function to swap to numbers
 * @num_1: the first number
 * @num_2: the second number
*/

void swap(int *num_1, int *num_2)
{
	int temp = *num_1;

	*num_1 = *num_2;
	*num_2 = temp;
}

/**
 * bubble_sort - function that do the bubble sort alogrithm
 * @array: the array whose hold the elements
 * @size: the size of the array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapp;

	if (!array || size < 2)
	{
		return;
	}

	for (i = 0; i < (size - 1); i++)
	{
		swapp = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapp = 1;
			}
		}
		if (swapp == 0)
			break;
	}
}
