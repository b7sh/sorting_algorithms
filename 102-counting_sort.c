#include "sort.h"

/**
 * max_num - find the maximum number in the array
 * @array: hold the elements
 * @size: the array size
*/

int max_num(int *array, int size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sort the array using counting sort
 * @array: hold the array elements
 * @size: the array size
*/

void counting_sort(int *array, size_t size)
{
	int *count, *temp;
	int l, i, j, m, max;

	if (!array || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (!temp)
		return;
	max = max_num(array, size);
	count = malloc((max + 1) * sizeof(int));
	if (!count)
	{
		free(temp);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		++count[array[i]];
	for (j = 1; j < (max + 1); j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);
	for (l = (int)size - 1; l >= 0; l--)
	{
		temp[count[array[l]] - 1] = array[l];
		--count[array[l]];
	}
	for (m = 0; m < (int)size; m++)
		array[m] = temp[m];
	free(count);
	free(temp);
}
