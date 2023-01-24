#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * findMax - finds the maximum value in an array oof integers
 * @array: the array to be traversed
 * @size: size of the array
 *
 * Return: the maximum value in the array
 */
int findMax(int *array, size_t size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, i, max, index;

	if (size < 2)
		return;
	max = findMax(array, size);
	count = (int *)malloc(sizeof(int) * (max + 1));
	output = (int *)malloc(sizeof(int) * size);
	if (count == NULL || output ==  NULL)
		return;
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, (max + 1));
	for (i = (int)size - 1; i >= 0; i--)
	{
		index = count[array[i]];
		output[index - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
