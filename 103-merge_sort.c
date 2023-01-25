#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * copyarray - creates a copy of an array
 * @array: array to b copied
 * @size: size of the array
 *
 * Return: the created copy
 */
int *copyarray(int *array, size_t size)
{
	int *new;
	size_t i;

	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		new[i] = array[i];
	return (new);
}

/**
 * merge - merges two sorted sublists of an array of integers
 * @array: array to be sorted
 * @start: lower bound
 * @mid: middle of the sublist
 * @end: upper boiund
 * @work_array: merge sorted array
 */
void merge(int *array, int start, int mid, int end, int *work_array)
{
	int i, k, j, iter;

	i = start;
	j = mid;
	printf("Merging...\n[left]: ");
	for (iter = start; iter < mid; iter++)
	{
		if (iter > start)
			printf(", ");
		printf("%d", array[iter]);
	}
	printf("\n[right]: ");
	for (iter = mid; iter < end; iter++)
	{
		if (iter > mid)
			printf(", ");
		printf("%d", array[iter]);
	}
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			work_array[k] = array[i];
			i++;
		}
		else
		{
			work_array[k] = array[j];
			j++;
		}
	}
	printf("\n[Done]: ");
	for (iter = start; iter < end; iter++)
	{
		if (iter > start)
			printf(", ");
		printf("%d", work_array[iter]);
	}
	printf("\n");
}

/**
 * TopDownSplitMerge - sorts an array of integers in ascending order using the
 * Mergesort algorithm from Top - Down
 * @work_array: copy of array
 * @start: start index of sublist
 * @end: end inde f sublist
 * @array: array to be sorted
 */
void TopDownSplitMerge(int *work_array, int start, int end, int *array)
{
	int mid;

	if (end - start <= 1)
		return;
	mid = (start + end) / 2;
	TopDownSplitMerge(array, start, mid, work_array);
	TopDownSplitMerge(array, mid, end, work_array);
	merge(work_array, start, mid, end, array);
}

/**
 * merge_sort - driver code for the sorting algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *new;

	if (size < 2)
		return;
	new = copyarray(array, size);
	if (new == NULL)
		return;
	TopDownSplitMerge(new, 0, (int)size, array);
}
