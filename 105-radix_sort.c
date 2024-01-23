#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);

void radix_sort(int *array, size_t size)
{
    size_t i;
    int exp;
    int max;

    if (array == NULL || size < 2)
        return;

    max = array[0];

    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        int count[10] = {0};
        ssize_t j;
        int *output = malloc(sizeof(int) * size);

        for (i = 0; i < size; ++i)
            count[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; ++i)
            count[i] += count[i - 1];

        for (j = size - 1; j >= 0; --j)
        {
            output[count[(array[j] / exp) % 10] - 1] = array[j];
            count[(array[j] / exp) % 10]--;
        }

        for (i = 0; i < size; ++i)
            array[i] = output[i];

        print_array(array, size);
        free(output);
    }
}
