#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers
 *  in ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int *output = NULL, *count = NULL;
	int i, j, max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	max++;
	count = malloc((size + 1) * sizeof(int));
	if (count == NULL)
		return;

	output = malloc((max + 1) * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		output[array[i]] = output[array[i]] + 1;

	for (j = 0; j < max; j++)
		output[j + 1] = output[j] + output[j + 1];

	print_array(output, max);

	for (i = 0; i < (int)size; i++)
	{
		count[output[array[i]] - 1] = array[i];
		output[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = count[i];

	free(output);
	free(count);
}
