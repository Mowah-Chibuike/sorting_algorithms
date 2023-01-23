#include "sort.h"

/**
 * swap - swap two elements in an array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j, swapped;

	gap = 1;
	while (gap < (int)size)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		swapped = 0;
		for (i = gap; i < (int)size; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j] < array[j + gap])
					break;
				swapped = 1;
				swap(&array[j], &array[j + gap]);
			}
		}
		if (swapped == 1)
			print_array(array, size);
		gap /= 3;
	}
}
