#include <stdio.h>
#include "sort.h"

/**
 * swap_heap - Swaps two elements in an array
 *
 * @array: The array containing the elements
 * @size: Size of the array
 * @a: Index of the first element
 * @b: Index of the second element
 *
 * Return: Nothing
 */

void swap_heap(int *array, size_t size, size_t a, size_t b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}

/**
 * sift_down - Perform the sift-down operation on a heap
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @n: Size of the heap
 * @i: Index of the root element
 *
 * Return: Nothing
 */

void sift_down(int *array, size_t size, size_t n, size_t i)
{
	size_t largest, left, right;

	while (i < n)
	{
		largest = i;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < n && array[left] > array[largest])
			largest = left;
		if (right < n && array[right] > array[largest])
			largest = right;
		if (largest != i)
		{
			swap_heap(array, size, i, largest);
			i = largest;
		} else
		{
			break;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, size, i);
	}
	for (i = size - 1; i > 0; i--)
	{
		swap_heap(array, size, 0, i);
		sift_down(array, size, i, 0);
	}
}

