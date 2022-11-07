#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 * @array: array to sort
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		if (!swap)
			return;
	}
}
