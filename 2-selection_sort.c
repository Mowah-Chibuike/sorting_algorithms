#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min_index;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
