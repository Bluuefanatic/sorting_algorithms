#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merge two halves of the array in bitonic order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @up: Boolean indicating the sorting order (1 for ascending, 0 for descending)
 * @bitonic_size: Size of the bitonic sequence
 */
void bitonic_merge(int *array, size_t size, int up, size_t bitonic_size)
{
    size_t i, j, step;

    if (bitonic_size > 1)
    {
        step = bitonic_size / 2;

        for (i = 0; i < size - step; ++i)
        {
            j = i + step;
            if ((array[i] > array[j]) == up)
            {
                /* Swap elements to maintain bitonic order */
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                /* Print the array after each swap */
                print_array(array, size);
            }
        }

        /* Recursively merge the two halves */
        bitonic_merge(array, step, up, bitonic_size / 2);
        bitonic_merge(array + step, step, up, bitonic_size / 2);
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @up: Boolean indicating the sorting order (1 for ascending, 0 for descending)
 * @bitonic_size: Size of the bitonic sequence
 */
void bitonic_sort_recursive(int *array, size_t size, int up, size_t bitonic_size)
{
    if (bitonic_size > 1)
    {
        size_t mid = size / 2;

        /* Sort the first half in ascending order */
        bitonic_sort_recursive(array, mid, 1, bitonic_size / 2);

        /* Sort the second half in descending order */
        bitonic_sort_recursive(array + mid, mid, 0, bitonic_size / 2);

        /* Merge the whole sequence */
        bitonic_merge(array, size, up, bitonic_size);
    }
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array (must be power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || (size & (size - 1)) != 0)
        return;

    bitonic_sort_recursive(array, size, 1, size);
}
