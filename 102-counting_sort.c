#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/* Function prototypes */
size_t find_max_value(int *array, size_t size);
void print_count_array(int *count_array, size_t size);

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array;
	size_t i, max_value;

	if (array == NULL || size < 2)
		return;

	max_value = find_max_value(array, size);

	count_array = malloc((max_value + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	/* Initialize count_array with zeros */
	for (i = 0; i <= max_value; i++)
		count_array[i] = 0;

	/* Count occurrences of each element in array */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Accumulate count_array values */
	for (i = 1; i <= max_value; i++)
		count_array[i] += count_array[i - 1];

	/* Print count_array once it is set up */
	print_count_array(count_array, max_value + 1);

	/* Build the sorted array */
	for (i = size - 1; i < size; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	/* Free dynamically allocated memory */
	free(count_array);
	free(sorted_array);
}

/**
 * find_max_value - Finds the maximum value in an array
 * @array: The array to find the maximum value in
 * @size: Number of elements in @array
 *
 * Return: The maximum value in the array
 */
size_t find_max_value(int *array, size_t size)
{
	size_t i, max_value;

	max_value = array[0];

	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max_value)
			max_value = array[i];
	}

	return (max_value);
}

/**
 * print_count_array - Prints the count array after it is set up
 * @count_array: The count array to be printed
 * @size: Number of elements in @count_array
 */
void print_count_array(int *count_array, size_t size)
{
	size_t i;

	printf("Counting array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", count_array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}
