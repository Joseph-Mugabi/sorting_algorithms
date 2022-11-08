#include "sort.h"

/**
 * prints_right_left - prints left, right, and merged halves
 *
 * @arry: temp array or original
 * @start: starting index
 * @end: ending index
 * @side: left, right, or merged half
 */
void prints_right_left(int *arry, char *side, size_t start, size_t end)
{
	size_t j;

	printf("[%s]: ", side);
	for (j = start; j < end; j++)
	{
		if (j != (end - 1))
			printf("%d, ", arry[j]);
		else
			printf("%d\n", arry[j]);
	}
}

/**
 * rec_merge - recursively splits and merges halves
 * @array: original array
 * @sortArr: tmp array to hold sorted elements
 * @l: starting index
 * @r: ending index
 */
void recursive_merge(int *array, int *sortArray, size_t l, size_t r)
{
	size_t i, l_half, r_half;
	size_t mid = (l + r) / 2;

	if (r - l <= 1)
		return;

	recursive_merge(array, sortArray, l, mid);
	recursive_merge(array, sortArray, mid, r);
	printf("Merging...\n");
	prints_right_left(array, "left", l, mid);
	prints_right_left(array, "right", mid, r);
	l_half = l;
	r_half = mid;
	for (i = l; i < r; i++)
	{
		if ((l_half < mid) &&
				((r_half == r) || (array[l_half] < array[r_half])))
		{
			sortArray[i] = array[l_half];
			l_half++;
		}
		else
		{
			sortArray[i] = array[r_half];
			r_half++;
		}
	}
	prints_right_left(sortArray, "Done", l, r);
	for (i = l; i < r; i++)
		array[i] = sortArray[i];
}
/**
 * merge_sort - sorts mergly
 * @array: array sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *sortArray;

	if (!(array) || size < 2)
		return;
	sortArray = malloc(sizeof(int) * size);
	if (!(sortArray))
		return;
	recursive_merge(array, sortArray, 0, size);
	free(sortArray);
}
