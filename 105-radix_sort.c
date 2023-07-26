#include "sort.h"

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @array_buffer: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *array_buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		array_buffer[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = array_buffer[i];
}

/**
 * radix_sort - Sort an array using the radix sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *array_buffer;

	if (array == NULL || size < 2)
		return;

	array_buffer = malloc(sizeof(int) * size);
	if (array_buffer == NULL)
		return;

	max = find_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, array_buffer);
		print_array(array, size);
	}

	free(array_buffer);
}
