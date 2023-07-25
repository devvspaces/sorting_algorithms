#include "sort.h"

/**
 * bubble_sort - using bubble sort algorithm
 * to sort an array
 *
 * @array: array to be sorted
 * @size: size of the array to be sorted
 *
 */
void bubble_sort(int *array, size_t size)
{
	int idx, tmp;
	int hi = size - 1;

	if (size <= 1)
		return;

	while (hi > 0)
	{
		for (idx = 0; idx < hi; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				tmp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmp;
				print_array(array, size);
			}
		}
		hi -= 1;
	}
}
