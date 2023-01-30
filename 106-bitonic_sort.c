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
 * Bitonic_Merge - merges two bitonic sequences according to specified
 * directions
 * @array: array to be sorted
 * @lb: lower boundary of sublist of array
 * @count: number of elements in sub_array
 * @direction: direction of sorting
 */
void Bitonic_Merge(int *array, int lb, int count, int direction)
{
	int i, k;

	if (count > 1)
	{
		k = count / 2;
		for (i = lb; i < lb + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
				swap(&array[i], &array[i + k]);
		}
		Bitonic_Merge(array, lb, k, direction);
		Bitonic_Merge(array, (lb + k), k, direction);
	}
}

/**
 * Bitonic_Sorter - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to be sorted
 * @lb: lower boundary of subarray
 * @count: number of elements in sub_array
 * @size: size of the array
 * @direction: direction to be sorted in
 */
void Bitonic_Sorter(int *array, int lb, int count, size_t size, int direction)
{
	int k, i;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%d/%ld] ", count, size);
		if (direction == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		for (i = lb; i < count + lb; i++)
		{
			if (i > lb)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");
		Bitonic_Sorter(array, lb, k, size, 1);
		Bitonic_Sorter(array, (lb + k), k, size, 0);
		Bitonic_Merge(array, lb, count, direction);
		printf("Result [%d/%ld] ", count, size);
		if (direction == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		for (i = lb; i < count + lb; i++)
		{
			if (i > lb)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");
	}
}

/**
 * bitonic_sort - driver code for sorting array using bitonic sort
 * @array: array to be sorted
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
	int total_size = (int)size;

	Bitonic_Sorter(array, 0, total_size, size, 1);
}
