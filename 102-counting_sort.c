#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_max - Find the maximum value in an array
 *
 * @array: The array to search
 * @size: The size of the array
 *
 * Return: The maximum value
 */

int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_elements - Count the occurrences of each element in an array
 *
 * @array: The array to count
 * @size: The size of the array
 * @max: The maximum value in the array
 *
 * Return: An array of counts
 */

int *count_elements(int *array, size_t size, int max)
{
	int *count;
	size_t i;
	int *counts;

	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return (NULL);
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	counts = malloc((max + 1) * sizeof(int));
	if (!counts)
	{
		free(count);
		return (NULL);
	}
	for (i = 0; i <= (size_t)max; i++)
		counts[i] = (i == 0) ? count[i] : counts[i - 1] + count[i];
	free(count);
	return (counts);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int *output;
	int *counts;
	int max;
	size_t i;

	if (!array || size < 2)
		return;
	max = find_max(array, size);
	if (max <= 0)
		return;
	counts = count_elements(array, size, max);
	if (!counts)
		return;
	print_array(counts, max + 1);
	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(counts);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[counts[array[i]] - 1] = array[i];
		counts[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(counts);
	free(output);
}
