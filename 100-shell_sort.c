#include "sort.h"

/**
 * shell_sort - function is to allow exchange of far items
 * @array: array pointer
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t  outer, inner;
	size_t interval = 1;
	int valueToInsert;

	if (array == NULL || size < 2)
		return;
	while (interval < size / 3)
		interval = interval * 3 + 1;
	while (interval > 0 )
	{
		for (outer = interval; outer < size; outer++)
		{
			valueToInsert = array[outer];
			inner = outer;
			while (inner > interval - 1 && array[inner - interval] >= valueToInsert)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}
			array[inner] = valueToInsert;
		}
		print_array(array, size);
		interval = (interval + 1) / 3;
	}
}
