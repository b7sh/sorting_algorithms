#include "sort.h"

/**
 * swap - swap two elements
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
 * partition - order of an array inteegrs
 * @array: hold the array elements
 * @size: the size of the array
 * @lower: the first element
 * @upper: the last element
 * Return: up
*/

int partition(int *array, size_t size, int lower, int upper)
{
	int *piviot = array + upper;
	int up, down;

	for (up = down = lower; down < upper; down++)
	{
		if (array[down] < *piviot)
		{
			if (up < down)
			{
				swap(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *piviot)
	{
		swap(array + up, piviot);
		print_array(array, size);
	}
	return (up);
}

/**
 * quicksort - function to implement the
 *  quick alogrithm
 *  @array: hold the elements
 *  @size: the size of the array
 *  @lower: the first element in the array
 *  @upper: the last element in the array
*/

void quicksort(int *array, size_t size, int lower, int upper)
{
	int par;

	if (upper - lower > 0)
	{
		par = partition(array, size, lower, upper);
		quicksort(array, size, lower, par - 1);
		quicksort(array, size, par + 1, upper);
	}
}

/**
 * quick_sort - function to sort the array by
 * usin the quick sort alogrithm
 * @array: hold the array elements
 * @size: the size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
