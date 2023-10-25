#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array_range - Print a range of integers from an array
 *
 * @array: The array to print values from
 * @start: The starting index
 * @end: The ending index
 *
 * Return: Nothing
 */

void print_array_range(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i <= end; i++)
	{
		if (i == start)
			printf("%d", array[i]);
		else
			printf(", %d", array[i]);
	}
}

/**
 * print_merge_info - Print merging information
 *
 * @left: The left subarray
 * @left_size: Number of elements in @left
 * @right: The right subarray
 * @right_size: Number of elements in @right
 * @result: The resulting sorted array
 *
 * Return: Nothing
 */

void print_merge_info(int *left, size_t left_size, int *right,
		size_t right_size, int *result)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_range(left, 0, left_size - 1);
	printf("\n[right]: ");
	print_array_range(right, 0, right_size - 1);
	i = j = k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			result[k++] = left[i++];
		else
			result[k++] = right[j++];
	}
	while (i < left_size)
	{
		result[k++] = left[i++];
	}
	while (j < right_size)
	{
		result[k++] = right[j++];
	}
	printf("\n[Done]: ");
	print_array_range(result, 0, left_size + right_size - 1);
	printf("\n");
}

/**
 * merge_arrays - Merges two sorted arrays into one sorted array
 *
 * @left: The left subarray
 * @left_size: Number of elements in @left
 * @right: The right subarray
 * @right_size: Number of elements in @right
 * @result: The resulting sorted array
 *
 * Return: Nothing
 */

void merge_arrays(int *left, size_t left_size, int *right,
		size_t right_size, int *result)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			result[k++] = left[i++];
		else
			result[k++] = right[j++];
	}
	while (i < left_size)
		result[k++] = left[i++];
	while (j < right_size)
		result[k++] = right[j++];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	int *temp_array;
	size_t middle, i;

	if (array == NULL || size < 2)
		return;
	if (size == 1)
		return;
	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;
	for (i = 0; i < size; i++)
		temp_array[i] = array[i];
	middle = size / 2;
	merge_sort(temp_array, middle);
	merge_sort(temp_array + middle, size - middle);
	print_merge_info(temp_array, middle, temp_array + middle,
			size - middle, array);
	free(temp_array);
}
