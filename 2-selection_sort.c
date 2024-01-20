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
 * selection_sort - function to sort the array using
 * selection sort alogrithm
 * @array: hold the array elements
 * @size: the size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t index_1, index_2;
	size_t minimum;

	if (array == NULL || size < 2)
		return;

	for (index_1 = 0; index_1 < (size - 1); index_1++)
	{
		minimum = index_1;

		for (index_2 = index_1 + 1; index_2 < size; index_2++)
		{
			if (array[index_2] < array[minimum])
			{
				minimum = index_2;
			}
		}
		if (minimum != index_1)
		{
			swap(&array[index_1], &array[minimum]);
			print_array(array, size);
		}
	}
}
