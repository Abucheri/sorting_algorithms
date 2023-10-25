#include "sort.h"
#include <stdio.h>

/**
 * swap_bitonic - Swap two elements in an array
 *
 * @array: The array to be modified
 * @i: Index of the first element
 * @j: Index of the second element
 *
 * Return: Nothing
 */

void swap_bitonic(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_merge - Merge the array in bitonic sequence
 *
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @count: The size of the subarray
 * @dir: Sorting direction (1 for increasing, 0 for decreasing)
 *
 * Return: Nothing
 */

void bitonic_merge(int *array, int low, int count, int dir)
{
	int k, i;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%d/%d] (%s):\n", count,
				(int)low + count, dir ? "UP" : "DOWN");
		print_array(array + low, count);
		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				swap_bitonic(array, i, i + k);
			}
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively perform bitonic sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @count: The size of the subarray
 * @dir: Sorting direction (1 for increasing, 0 for decreasing)
 *
 * Return: Nothing
 */

void bitonic_sort_recursive(int *array, int low, int count, int dir)
{
	int k;

	if (count > 1)
	{
		k = count / 2;
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	printf("Original array:\n");
	print_array(array, size);
	bitonic_sort_recursive(array, 0, size, 1);
	printf("Sorted array:\n");
	print_array(array, size);
}
