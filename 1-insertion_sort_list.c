#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: a double list from an array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *current;

	if (list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		for (index = current; index != NULL; index = index->prev)
		{
			if (index->n > current->n && index->prev == NULL && current->next == NULL)
			{
				swap_nodes(index);
				*list = index->prev;
				print_list(*list);
			}
			else if (index->n > current->n && index->prev == NULL)
			{
				swap_node(index);
				*list = index->prev;
				print_list(*list);
			}
			else if (index->n > current->n && index->prev != NULL)
			{
				if (index->n > current->n && current->next == NULL)
				{
					swapLast(index);
					print_list(*list);
				}
				else
				{
					swapTwo(index);
					print_list(*list);
				}
			}
		}
		current = current->next;
		index = current;
	}
}

/**
 * swap_nodes - function that swaps two nodes
 * @index: input pointer
 */
void swap_nodes(listint_t *index)
{
	index->next->prev = NULL;
	index->prev = index->next;
	index->next = NULL;
	index->prev->next = index;
}

/**
 * swap_node - swap two nodes to form list
 * @index: pointer to previous node
 */
void swap_node(listint_t *index)
{
	index->prev = index->next;
	index->next->next->prev = index;
	index->next = index->next->next;
	index->prev->prev = NULL;
	index->prev->next = index;
}

/**
 * swapLast - function that exchanges the last node
 * @index: pointer to input
 */
void swapLast(listint_t *index)
{
	index->prev->next = index->next;
	index->next->next = index;
	index->next->prev = index->prev;
	index->prev = index->next;
	index->next = NULL;
}

/**
 * swapTwo - swap two nodes of a list doubly links
 * @index: pointer to previous node
 */
void swapTwo(listint_t *index)
{
	index->next->next->prev = index;
	index->next->prev = index->prev;
	index->prev = index->next;
	index->next = index->next->next;
	index->prev->prev->next = index->prev;
	index->prev->next = index;
}
