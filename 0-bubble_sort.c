#include "sort.h"
/**
 * bubble_sort - Sorts arrays of int in ascending order
 * @array: the array
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t step;

	if (array == NULL || size < 2)
		return;

/*loop to access each element of the array - outer loop*/
	for (step = 0; step <= (size - 1); step++)
	{
		int swap_count = 0;
		size_t i;
/*loop over each element of the array to compare them - inner loop*/
		for (i = 0; i < (size - step - 1); i++)
		{
			/*compare 2 adjacent elemts and swap into ascending order*/
			if (array[i] > array[i + 1])
			{
				int temp = array[i];

				array[i] = array[i + 1];

				array[i + 1] = temp;

				swap_count += 1;
				print_array(array, size);
			}
		}

		if (swap_count == 0)
			break;
	}
}
