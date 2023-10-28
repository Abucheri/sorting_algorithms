#include "sort.h"

/**
 * swap_quicksort - swaps integers
 *
 * @i: first integer
 * @j: second integer
 *
 * Return: Nothing
 */

void swap_quicksort(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * quicksort_hoare - Implements the Quick sort algorithm using the Hoare
 * partition scheme.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 *
 * Return: Nothing
 */

void quicksort_hoare(int *array, size_t size, int low, int high)
{
	int pivot;

	if (high - low > 0)
	{
		pivot = hoare_partition(array, size, low, high);
		quicksort_hoare(array, size, low, pivot - 1);
		quicksort_hoare(array, size, pivot, high);
	}
}

/**
 * hoare_partition - Implements the Hoare partition scheme for Quick sort.
 *
 * @array: The array to be partitioned
 * @size: Size of the array
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 *
 * Return: The index of the pivot element
 */

int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i;
	int j;

	for (i = low - 1, j = high + 1; i < j;)
	{
		do
			i++;
		while (array[i] < pivot);
		do
			j--;
		while (array[j] > pivot);
		if (i < j)
		{
			swap_quicksort(array + i, array + j);
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * quick_sort_hoare - Sorts an array of integers using the
 * Quick sort algorithm with the Hoare partition scheme.
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_hoare(array, size, 0, size - 1);
}
