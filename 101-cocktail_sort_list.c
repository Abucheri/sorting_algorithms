#include "sort.h"

/**
 * swap_forward - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it
 *
 * @list: A pointer to the head of a doubly-linked list of integers
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the cocktail
 * algorithm
 *
 * Return: Nothing
 */

void swap_forward(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_backward - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it
 *
 * @list: A pointer to the head of a doubly-linked list of integers
 * @tail: A pointer to the tail of the doubly-linked list
 * @shaker: A pointer to the current swapping node of the cocktail shaker
 * algorithm
 */

void swap_backward(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

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
	listint_t *tail, *shaker;
	bool stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
	{
		tail = tail->next;
	}
	while (stirred == false)
	{
		stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_forward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_backward(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
	}
}
