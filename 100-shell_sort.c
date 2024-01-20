#include <stddef.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap using Knuth sequence */
	while (gap < size)
		gap = gap * 3 + 1;

	/* Start sorting with decreasing gaps */
	while (gap > 0)
	{
		gap /= 3;

		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* Move elements with gap intervals */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		/* Print the array each time the gap decreases */
		print_array(array, size);
	}
}
