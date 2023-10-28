#include "sort.h"
#include <stdio.h>

/**
 * swap_bitonic - Swap two elements in an array
 *
 * @i: first element
 * @j: second element
 *
 * Return: Nothing
 *
 * Description: This function swaps two elements in an array
 */

void swap_bitonic(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * bitonic_merge - Merge the array in bitonic sequence
 *
 * @size: The size of the array
 * @start: The starting index of the sequence to sort
 * @seq: The size of the sequence to sort
 * @flow: The direction to sort in (UP or DOWN)
 *
 * Return: Nothing
 *
 * Description: This function merges the array into a bitonic sequence
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_bitonic(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sort_recursive - Recursively perform bitonic sort
 *
 * @array: An array of integers
 * @size: The size of the array
 * @start: The starting index of the building bitonic sequence
 * @seq: The size of the block of the bitonic sequence
 * @flow: The direction to sort the bitonic sequence block in (UP or DOWN)
 *
 * Return: Nothing
 *
 * Description: This function performs bitonic sort recursively
 */

void bitonic_sort_recursive(int *array, size_t size,
		size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
		bitonic_sort_recursive(array, size, start, cut, UP);
		bitonic_sort_recursive(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);
		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 *
 * Description: Prints the array after each swap. Works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2)
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	bitonic_sort_recursive(array, size, 0, size, UP);
}
