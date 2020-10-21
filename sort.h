#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

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
void swap(int *xp, int *yp);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t *index);
void swap_node(listint_t *index);
void swapLast(listint_t *index);
void swapTwo(listint_t *index);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_cocktail(listint_t *current1, listint_t *current2, listint_t **list);

#endif /* SORT_H */
