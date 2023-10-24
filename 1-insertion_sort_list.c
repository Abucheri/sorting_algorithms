#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to a pointer to the head of the list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		insertion = current;
		current = current->next;
		while (insertion->prev && insertion->n < insertion->prev->n)
		{
			temp = insertion->prev;
			insertion->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = insertion;
			else
				*list = insertion;
			temp->next = insertion->next;
			if (insertion->next)
				insertion->next->prev = temp;
			insertion->next = temp;
			temp->prev = insertion;
			print_list(*list);
		}
	}
}
