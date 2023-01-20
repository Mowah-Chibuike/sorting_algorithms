#include "sort.h"

/**
 * compare - compares the values of two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: true if a > b, otherwise false
 */
int compare(int a, int b)
{
	return (a > b);
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
	size_t i, j, swaps, temp;

	for (i = 0; i < size; i++)
	{
		swaps = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (compare(array[j], array[j + 1]))
			{
				swaps++;
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		if (swaps == 0)
			return;
	}
}
