#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Get the maximum element in the array
 *
 * @array: The array to search
 * @size: Size of the array
 *
 * Return: The maximum element
 */

int get_max(int *array, size_t size)
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
 * counting_sort_radix - Perform counting sort on array based
 * on significant digit
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The current significant digit to consider
 *
 * Return: Nothing
 */

void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	int i;
	size_t j;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (j = size - 1; (int)j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * LSD Radix Sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
