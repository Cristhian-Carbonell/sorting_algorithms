#include "sort.h"

/**
 * bubble_sort -function that sorts an array
 *of integers in ascending order using the Bubble sort algorithm
 * @array: set matrix for exchange
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (arra == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}

/**
 * swap - swaps the values of two integers
 * @xp: pointer to int to be swapped
 * @yp: pointer to other int to be swapped
 */
void swap(int *xp, int *yp)
{
	size_t temp = *xp;

	*xp = *yp;
	*yp = temp;
}
