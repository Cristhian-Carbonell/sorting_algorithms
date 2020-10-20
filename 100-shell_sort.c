#include "sort.h"

/**
 * shell_sort - function is to allow exchange of far items
 * @array: array pointer
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp, n = size + 1;

	if (array == NULL)
		return;
	for (gap = (n * 3) + 1; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
