#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @left: The left node to be swapped
 * @right: The right node to be swapped
 * @list: Pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	if (right->next != NULL)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		/* Move forward through the list */
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
				print_list(*list);
			}
		}

		/* Move backward through the list */
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
