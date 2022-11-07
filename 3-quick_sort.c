#include "sort.h"

int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot, i, j;
	int tmp;

	pivot = array[right];
	for (i = j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		tmp = array[i];
		array[i] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}
	return (i);
}
/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 *
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
