#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: A pointer to a pointer to the head of the list
 *
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (!list || !(*list))
		return;
	while (swapped)
	{
		swapped = 0;
		for (curr = *list; curr && curr->next; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_list_nodes(curr, curr->next, list);
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; curr && curr->prev; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_list_nodes(curr->prev, curr, list);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_list_nodes - Swaps two nodes in a doubly linked list
 *
 * @node1: The first node to swap
 * @node2: The second node to swap
 * @list: A pointer to the head of the list
 *
 * Return: Nothing
 */

void swap_list_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *prev_node1, *next_node2;

	prev_node1 = node1->prev;
	next_node2 = node2->next;
	if (prev_node1)
		prev_node1->next = node2;
	else
		*list = node2;
	if (next_node2)
		next_node2->prev = node1;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = prev_node1;
	node1->next = next_node2;
}
