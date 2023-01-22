#include "sort.h"
#include <stdio.h>

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
 * bubble_sort - sorts an array of integers using the bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Description: prints the lisst each  time two elements are swaped
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, temp;

	if (size < 2)
		return;
	if (size == 2 && array[0] > array[1])
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
		print_array(array, size);
	}
	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapped = 1;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
