#include "sort.h"

/**
 * swap - Swaps two elements in an array and prints the result
 * @array: The array containing the elements
 * @i: Index of the first element to swap
 * @j: Index of the second element to swap
 * @size: Total size of the array (needed for printing)
 *
 */
void swap(int *array, size_t i, size_t j, size_t size)
{
	int temp;

	/* Only swap if the indices are different */
	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		/* Print array after each swap to track sorting progress */
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions array using Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot position)
 * @size: Total size of the array (needed for printing)
 *
 * Return: Final index position of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			/* Place it in the "smaller elements" section */
			swap(array, i, j, size);
			i++;
		}
	}
	/* Place pivot in its correct position (between smaller and larger) */
	swap(array, i, high, size);
	return (i);
}

/**
 * quick_sort_recursive - Recursive implementation of quick sort
 * @array: The array to be sorted
 * @low: Starting index of the current partition
 * @high: Ending index of the current partition
 * @size: Total size of the array (needed for printing)
 *
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_idx;

	/* Base case: if low >= high, partition has 0 or 1 element */
	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);

		/* Recursively sort left sub-array (elements before pivot) */
		/* Check pivot_idx > 0 to avoid underflow with size_t */
		if (pivot_idx > 0)
			quick_sort_recursive(array, low, pivot_idx - 1, size);

		/* Recursively sort right sub-array (elements after pivot) */
		quick_sort_recursive(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - Main function to sort array using Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */
void quick_sort(int *array, size_t size)
{
	/* Handle edge cases: null array or arrays with < 2 elements */
	if (!array || size < 2)
		return;

	/* Start recursive sorting with full array range */
	quick_sort_recursive(array, 0, size - 1, size);
}
