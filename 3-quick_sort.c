#include "sort.h"

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 *
 * Description: This function implements the recursive step of the Quick sort
 *              algorithm using the Lomuto partition scheme. It selects a pivot
 *              from the partition and recursively sorts the subarrays on both
 *              sides of the pivot.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size);

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot after partitioning
 *
 * Description: This function implements the Lomuto partition scheme for Quick
 *              sort. It selects the last element of the partition as the pivot,
 *              places the pivot in its correct position, and rearranges the
 *              elements such that elements smaller than the pivot are on its
 *              left, and elements greater are on its right.
 */
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the Quick sort algorithm with the Lomuto partition scheme.
 *              It calls the recursive helper function quick_sort_recursive.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/* Swap elements */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}

	/* Swap pivot to its final position */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	/* Print the array after swapping pivot */
	print_array(array, size);

	return (i + 1);
}
