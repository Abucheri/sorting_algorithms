#ifndef SORT_H
#define SORT_H

#include <stddef.h>

typedef int bool;
#define true 1
#define false 0

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int low, int high);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_forward(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_backward(listint_t **list, listint_t **tail, listint_t **shaker);
void counting_sort(int *array, size_t size);
int find_max(int *array, size_t size);
int *count_elements(int *array, size_t size, int max);
void merge_sort(int *array, size_t size);
void merge_arrays(int *left, size_t left_size, int *right,
		size_t right_size, int *result);
void print_array_range(int *array, size_t start, size_t end);
void print_merge_info(int *left, size_t left_size, int *right,
		size_t right_size, int *result);
void heap_sort(int *array, size_t size);
void swap_heap(int *array, size_t size, size_t a, size_t b);
void sift_down(int *array, size_t size, size_t n, size_t i);

#endif
