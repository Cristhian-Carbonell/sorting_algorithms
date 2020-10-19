#include "sort.h"

/**
 * selection_sort - function to order whyt the method selection
 *@array: value
 *@size: value
 * print_list - function to be printed
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;

	if (array == NULL || size < 2)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[k])
				k = j;
		if (i != k)
		{
			swap(&array[k], &array[i]);
			print_array(array, size);
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
