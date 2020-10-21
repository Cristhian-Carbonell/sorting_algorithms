#include "sort.h"

/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail shaker sort algorithm
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swappend = 1;

	if (list == NULL && (*list)->next == NULL)
		return;
	current = *list;
	while (swappend)
	{
		swappend = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_node_cocktail(current, current->next, list);
				swappend = 1;
			}
			else
				current = current->next;
		}
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_node_cocktail(current->prev, current, list);
					swappend = 1;
			}
			else
				current = current->prev;
		}
	}
}

/**
 * swap_node_cocktail - exchange of two nodes
 * @current1: current node
 * @current2:
 * @list: doubly linked list
 */
void swap_node_cocktail(listint_t *current1, listint_t *current2, listint_t **list)
	{
	if (current2->next != NULL)
		current2->next->prev = current1;
	if (current1->prev != NULL)
	{
		current2->prev = current1->prev;
		current2->prev->next = current2;
	}
	else
	{
		current2->prev = NULL;
		*list = current2;
	}
	current1->prev = current1->next;
	current1->next = current2->next;
	current1->prev->next = current1;
	current2->next = current1;
	print_list(*list);
}
