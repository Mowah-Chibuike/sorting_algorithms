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
 * Partition - partitions and array uing Lomuto partition scheme
 * @array: array to be partitioned
 * @start: start of the part of the array to be partitioned
 * @end: end of the part of the array to be partitioned
 * @size: size of the array
 *
 * Return: the index of the pivot after partitioning
 */
int Partition(int *array, int start, int end, int size)
{
	int i, pIndex;
	int pivot;

	pIndex = start;
	pivot = array[end];
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[pIndex]);
			if (i != pIndex)
				print_array(array, size);
			pIndex++;
		}
	}
	swap(&array[pIndex], &array[end]);
	if (pivot != array[end])
		print_array(array, size);
	return (pIndex);
}

/**
 * Quick_Sort - sorts an array of integers in ascending order using the Quick
 * sort algorithm
 * @array: array to be sorted
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array to be sorted
 */
void Quick_Sort(int *array, int start, int end, int size)
{
	int pIndex;

	if (start < end)
	{
		pIndex = Partition(array, start, end, size);
		Quick_Sort(array, start, pIndex - 1, size);
		Quick_Sort(array, pIndex + 1, end, size);
	}
}


/**
 * quick_sort - driver for the quic ort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	Quick_Sort(array, 0, (int)(size - 1), (int)size);
}
