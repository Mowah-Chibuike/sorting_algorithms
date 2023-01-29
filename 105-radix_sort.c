#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * getMax - finds the largest number in a list of integers
 * @array: array to be traversed
 * @size: size of the array
 *
 * Return: the largest integer in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * copy_array - creates a copy of an array of integers
 * @array: array to be copied
 * @size: size of the array
 *
 * Return: the copied array
 */
int *copy_array(int *array, size_t size)
{
	int *copy;
	size_t i;

	copy = (int *)malloc(sizeof(int) * size);
	if (copy == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		copy[i] = array[i];

	return (copy);
}

/**
 * count_sort - sorts an array using count sort
 * @array: array to be sorted
 * @size: size of the array
 * @position: the particular digit we are sorted according to
 * @output: the output array
 */
void count_sort(int *array, size_t size, int position, int *output)
{
	int count[10], index, i, len = (int)size;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = len - 1; i >= 0; i--)
	{
		index = (array[i] / position) % 10;
		count[index] += 1;
	}

	for (i = 1; i < len; i++)
		count[i] += count[i - 1];

	for (i = len - 1; i >= 0; i--)
	{
		index = (array[i] / position) % 10;
		count[index] -= 1;
		output[count[index]] = array[i];
	}

	for (i = 0; i < len; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, pos, *output;

	max = getMax(array, size);
	output = copy_array(array, size);
	if (output == NULL)
		return;

	for (pos = 1; max / pos > 0; pos *= 10)
	{
		count_sort(array, size, pos, output);
		print_array(array, size);
	}
	free(output);
}
