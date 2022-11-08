#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: array to sort
 * @size: the size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
		gap /= 3;
	}
}