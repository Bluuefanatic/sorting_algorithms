#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_arrays - Merges two subarrays into a single sorted array
 * @array: The array to be sorted
 * @temp_array: Temporary array to store merged results
 * @start: Starting index of the first subarray
 * @middle: Ending index of the first subarray
 * @end: Ending index of the second subarray
 */
void merge_arrays(int *array, int *temp_array, size_t start, size_t middle, size_t end)
{
	size_t i, j, k;

	i = start;
	j = middle + 1;
	k = start;

	while (i <= middle && j <= end)
	{
		if (array[i] <= array[j])
		{
			temp_array[k] = array[i];
			i++;
		}
		else
		{
			temp_array[k] = array[j];
			j++;
		}
		k++;
	}

	while (i <= middle)
	{
		temp_array[k] = array[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		temp_array[k] = array[j];
		j++;
		k++;
	}

	for (i = start; i <= end; i++)
	{
		array[i] = temp_array[i];
	}
}

/**
 * merge_sort_recursive - Recursively sorts the array using merge sort
 * @array: The array to be sorted
 * @temp_array: Temporary array to store merged results
 * @start: Starting index of the array
 * @end: Ending index of the array
 */
void merge_sort_recursive(int *array, int *temp_array, size_t start, size_t end)
{
	size_t middle;

	if (start < end)
	{
		middle = (start + end) / 2;
		merge_sort_recursive(array, temp_array, start, middle);
		merge_sort_recursive(array, temp_array, middle + 1, end);
		merge_arrays(array, temp_array, start, middle, end);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using merge sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array = malloc(size * sizeof(int));

	if (!temp_array)
		return;

	merge_sort_recursive(array, temp_array, 0, size - 1);

	free(temp_array);
}
