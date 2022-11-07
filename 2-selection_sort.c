#include "sort.h"

/**
 * selection_sort -  function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int idx = 0, min, tmp, swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		swap = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
			swap = 1;
		}
		if (!swap)
			return;
	}
}
