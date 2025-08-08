#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp;

    if (!array || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        /* Find the minimum element in the remaining unsorted array */
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        /* Swap the found minimum element with the first element */
        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;

            /* Print array after each swap */
            print_array(array, size);
        }
    }
}
