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
 * @node1: current first node
 * @node2: current second node
 * @list: doubly linked list
 */
void swap_node_cocktail(listint_t *node1, listint_t *node2, listint_t **list)
	{
	if (node2->next != NULL)
		node2->next->prev = node1;
	if (node1->prev != NULL)
	{
		node2->prev = node1->prev;
		node2->prev->next = node2;
	}
	else
	{
		node2->prev = NULL;
		*list = node2;
	}
	node1->prev = node1->next;
	node1->next =  node2->next;
	node1->prev->next =  node1;
	node2->next = node1;
	print_list(*list);
}
