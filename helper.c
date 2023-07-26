#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 *
 * @a: The first integer.
 * @b: The second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * find_max - Find the maximum value in an array of integers.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}
