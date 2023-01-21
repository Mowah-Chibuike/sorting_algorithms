#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 *
 * Description: prints the lisst each  time two elements are swaped
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, temp, start, end;
	int swapped = 1;

	start = 0;
	end = size;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < end - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapped = 1;
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;

		--end;
		
		swapped = 0;

		for (i = end - 1; i > start; i--)
		{
			if (array[i] > array[i + 1])
			{
				swapped = 1;
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}

		++start;
	}
}
