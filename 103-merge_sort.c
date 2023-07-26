#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 *
 * @subarr: A subarray of an array of integers to sort.
 * @arr_buffer: A bufferer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *arr_buffer, size_t front, size_t mid,
				  size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		arr_buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		arr_buffer[k++] = subarr[i];
	for (; j < back; j++)
		arr_buffer[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = arr_buffer[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - merge sort algorithm using recursion.
 *
 * @subarr: A subarray of an array of integers to sort.
 * @arr_buffer: A arr_bufferer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *arr_buffer, size_t front,
							size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, arr_buffer, front, mid);
		merge_sort_recursive(subarr, arr_buffer, mid, back);
		merge_subarr(subarr, arr_buffer, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array using the merge sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *arr_buffer;

	if (array == NULL || size < 2)
		return;

	arr_buffer = malloc(sizeof(int) * size);
	if (arr_buffer == NULL)
		return;

	merge_sort_recursive(array, arr_buffer, 0, size);

	free(arr_buffer);
}
