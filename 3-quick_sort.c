#include "sort.h"

/**
 * swap - Swaps two integers in an array
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 *
 * @array: The array to be partitioned
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot
 */

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursively sorts an array using the Quick Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Nothing
 */

void quicksort(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		quicksort(array, size, low, pivot_index - 1);
		quicksort(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * quick sort algorithm (Lomuto partition scheme)
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
