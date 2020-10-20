#include "sort.h"

/**
 * shell_sort - function is to allow exchange of far items
 * @array: array pointer
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 0, outer, inner;
	size_t interval = size + 1;
	int valueToInsert;

	if (array == NULL)
		return;
	while (interval <= size/3)
		interval = interval * 3 + 1;
	while (interval > 0)
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
		interval = (interval + 1) / 3;
		i++;
		print_array(array, size);
	}
}
