#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare two cards for sorting
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = *(const card_t **)a;
	const card_t *card_b = *(const card_t **)b;

	if (card_a->kind == card_b->kind)
		return (strcmp(card_a->value, card_b->value));

	return (card_a->kind - card_b->kind);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	deck_node_t *node = *deck;
	card_t *cards[52];

	for (i = 0; i < 52; ++i)
	{
		cards[i] = (card_t *)node->card;
		node = node->next;
	}

	qsort(cards, 52, sizeof(card_t *), compare_cards);

	node = *deck;
	for (i = 0; i < 52; ++i)
	{
		node->card = cards[i];
		node = node->next;
	}
}
