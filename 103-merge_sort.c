#include "sort.h"

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: array to sort
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	recursion_merge(array, size, temp);
	free(temp);
}

/**
 * recursion_merge - call of the function
 * @array: elemete array
 * @size: array size
 * @temp: temporary array for malloc
 */
void recursion_merge(int *array, size_t size, int *temp)
{
	int m;

	if (array == NULL || size < 2)
		return;

	m = size / 2;
	recursion_merge(array, m, temp);
	recursion_merge(array + m, size - m, temp);
	merge(array, array + m, m, size - m, temp);
}

/**
 * merge - merges two subarrays of array
 * @array1: Firts subarray
 * @array2: secong subarray
 * @m: array size1
 * @size: array size2
 * @temp: temporary array whete the two subarray will merge
 */
void merge(int *array1, int *array2, int m, size_t size, int *temp)
{
	int i, j = 0, k = 0, size_merge;

	size_merge = m + size;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array1, m);
	printf("[right]: ");
	print_array(array2, size);
	for (i = 0; k < size_merge; k++)
	{
		if (i >= m)
		{
			temp[k] = array2[j];
			j++;
		}
		else if (j >= (int)size)
			temp[k] = array1[i++];
		else if (array1[i] < array2[j])
			temp[k] = array1[i++];
		else
			temp[k] = array2[j++];
	}
	for (i = 0; i < size_merge; i++)
		array1[i] = temp[i];
	printf("[Done]: ");
	print_array(array1, size_merge);
}
