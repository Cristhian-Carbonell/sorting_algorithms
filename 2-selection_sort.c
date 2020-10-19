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
