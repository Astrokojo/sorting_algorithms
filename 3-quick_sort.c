#include "sort.h"

/**
 * swap_arr_item - Swaps two items in an array.
 * @array: The array to modify.
 * @left: The index of the left item.
 * @right: The index of the right item.
 */
void swap_arr_item(int *array, size_t left, size_t right)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
	}
}

/**
 * lomuto_sort - Sorts a sub array using the
 * quick sort algorithm and Lomuto's partition scheme.
 * @array: The array containing the sub-array.
 * @start: The starting position of the sub-array.
 * @end: The ending position of the sub-array.
 * @size: The length of the array.
 */
void lomuto_sort(int *array, size_t start, size_t end, size_t size)
{
	size_t k, i;
	int pivot;

	if ((start >= end) || (array == NULL))
		return;
	pivot = array[end];
	k = start;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				swap_arr_item(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != end)
	{
		swap_arr_item(array, k, end);
		print_array(array, size);
	}
	if (k - start > 1)
		lomuto_sort(array, start, k - 1, size);
	if (end - k > 1)
		lomuto_sort(array, k + 1, end, size);
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		lomuto_sort(array, 0, size - 1, size);
	}
}
