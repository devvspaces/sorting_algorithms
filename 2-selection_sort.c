#include "sort.h"
/**
 * selection_sort - sort using the selection sort algorithm.
 *
 * @array: array to sort
 * @size: size of array
 *
 * Description: Prints the array after each swap.
 *
 * Returns: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, i2;
	int min, temp, index;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (i2 = i + 1; i2 < size; i2++)
		{
			if (min > array[i2])
			{
				min = array[i2];
				index = i2;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = min;
			array[index] = temp;
			print_array(array, size);
		}
	}
}
