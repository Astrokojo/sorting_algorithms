#include "sort.h"
/**
 * selection_sort - uses selection sort to srot
 *	  array of integerin ascending order.
 * @array: the array
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index, j;

	for (i = 0; i < (size - 1); i++)
	{
        int swap_count = 0;
		index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			index = j;
		    swap_count += 1;
			print_array(array, size);
		}

		if (swap_count == 0)
			break;
	}
}
