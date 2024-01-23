#include "sort.h"

/**
 * sift_down - Perform heapify operation on the heap.
 * @array: The array to heapify.
 * @size: Size of the array.
 * @root: Root index.
 * @end: Last index of the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t max, left_child, right_child;

	max = root;
	left_child = 2 * root + 1;
	right_child = 2 * root + 2;

	if (left_child < end && array[left_child] > array[max])
		max = left_child;

	if (right_child < end && array[right_child] > array[max])
		max = right_child;

	if (max != root)
	{
		/* Swap root and max */
		array[root] ^= array[max];
		array[max] ^= array[root];
		array[root] ^= array[max];
		print_array(array, size);
		sift_down(array, size, max, end);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	/* Build max heap */
	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		/* Swap root and last element */
		array[0] ^= array[i];
		array[i] ^= array[0];
		array[0] ^= array[i];
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
