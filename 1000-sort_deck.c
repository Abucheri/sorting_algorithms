#include <stdlib.h>
#include "deck.h"
#include <string.h>

/**
 * card_cmp - Compare function for qsort
 *
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Result of comparison
 */

int card_cmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	if (*a != *b)
	{
		return (*a - *b);
	}
	return (0);
}

/**
 * card_val - gets numerical card value
 *
 * @c_val: pointer to card
 *
 * Return: value of the card in numerical format
 */

char card_val(deck_node_t *c_val)
{
	if (card_cmp(c_val->card->value, "Ace") == 0)
		return (0);
	if (card_cmp(c_val->card->value, "1") == 0)
		return (1);
	if (card_cmp(c_val->card->value, "2") == 0)
		return (2);
	if (card_cmp(c_val->card->value, "3") == 0)
		return (3);
	if (card_cmp(c_val->card->value, "4") == 0)
		return (4);
	if (card_cmp(c_val->card->value, "5") == 0)
		return (5);
	if (card_cmp(c_val->card->value, "6") == 0)
		return (6);
	if (card_cmp(c_val->card->value, "7") == 0)
		return (7);
	if (card_cmp(c_val->card->value, "8") == 0)
		return (8);
	if (card_cmp(c_val->card->value, "9") == 0)
		return (9);
	if (card_cmp(c_val->card->value, "10") == 0)
		return (10);
	if (card_cmp(c_val->card->value, "Jack") == 0)
		return (11);
	if (card_cmp(c_val->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_deck - sort a deck by kind
 *
 * @deck: pointer to the head
 *
 * Return: Nothing
 */

void insert_deck(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insert_deck_val - sort a deck by value
 *
 * @deck: pointer to the head
 *
 * Return: Nothing
 */

void insert_deck_val(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind == iter->card->kind &&
				card_val(insert) > card_val(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sorts a deck of cards
 *
 * @deck: Pointer to a doubly linked list of cards
 *
 * Return: Nothing
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	insert_deck(deck);
	insert_deck_val(deck);
}
