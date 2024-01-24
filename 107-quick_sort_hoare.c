#include "sort.h"

void _quick_sort_hoare(int *array, int low, int high);
int hoare_partition(int *array, int low, int high);
void swap(int *array, int i, int j);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort_hoare(array, 0, size - 1);
}

/**
 * _quick_sort_hoare - Helper function for Quick sort (Hoare partition scheme)
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */
void _quick_sort_hoare(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high);

		/* Recursively sort the sub-arrays */
		_quick_sort_hoare(array, low, pivot);
		_quick_sort_hoare(array, pivot + 1, high);
	}
}

/**
 * hoare_partition - Hoare partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partitioning
 */
int hoare_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(array, i, j);
		print_array(array, high + 1);
	}
}

/**
 * swap - Swaps two elements in an array
 * @array: The array containing the elements
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}
