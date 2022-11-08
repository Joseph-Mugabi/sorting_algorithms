#include "sort.h"

/**
 * counting_sort -  function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * 
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counts, dup;
	int j, k, b;

	if (!array || size < 2)
		return;

	k = array[0]; /* max number in array*/
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	counts = malloc(sizeof(int) * (k + 1));
	if (!counts)
		return;

	for (j = 0; j < (k + 1); j++)
		 counts[j] =0; /* memset arr count to 0*/
	for (i = 0; i < size; i++)
	{
		b = array[i];
		counts[b] += 1;
	}
	for (j = 0; j < k; j++)
	{
		counts[j + 1] += counts[j];
	}
	print_array(counts, k + 1);
	for (i = 0, j = 0; j < k; j++) /* regenerate a sorted array with dup*/
	{
		if ((j == 0) && counts[j] != 0)
		{
			for ((dup = counts[j]); dup > 0; dup--)
				array[i++] = j;
		}
		if (counts[j + 1] > counts[j])
		{
			for ((dup = counts[j + 1] - counts[j]); dup > 0; dup--)
				array[i++] = (j + 1);
		}
	}
	free(counts);
}
