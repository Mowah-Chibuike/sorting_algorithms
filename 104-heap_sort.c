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
 * max_heapify - orders an array ina sift-down method
 * @array: array to be heaped
 * @size: size of the part of heap to be sorted
 * @i: index to be checked
 * @main_size: main size of the arry
 */
void max_heapify(int *array, int size, int i, int main_size)
{
	int left, right, largest;

	largest = i - 1;
	left = (i * 2) - 1;
	right = left + 1;
	while (left < size && array[left] > array[largest])
		largest = left;
	while (right < size && array[right] > array[largest])
		largest = right;
	if (largest + 1 != i)
	{
		swap(&array[i - 1], &array[largest]);
		print_array(array, main_size);
		max_heapify(array, size, largest + 1, main_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap
 * sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, j, new_size = (int)size;

	for (i = new_size / 2; i > 0; i--)
		max_heapify(array, new_size, i, new_size);

	for (i = new_size; i > 0; i--)
	{
		swap(&array[i - 1], &array[0]);
		if (i > 1)
			print_array(array, size);
		for (j = i / 2; j > 0; j--)
			max_heapify(array, i - 1, j, new_size);
	}
}
