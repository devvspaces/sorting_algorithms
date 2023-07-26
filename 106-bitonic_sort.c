#include "sort.h"

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq_size: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq_size,
				   char flow)
{
	size_t i, jump = seq_size / 2;

	if (seq_size > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
				(flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq_size: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq_size,
					char flow)
{
	size_t cut = seq_size / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq_size, size, str);
		print_array(array + start, seq_size);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq_size, flow);

		printf("Result [%lu/%lu] (%s):\n", seq_size, size, str);
		print_array(array + start, seq_size);
	}
}

/**
 * bitonic_sort - Sort an array using the bitonic sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
