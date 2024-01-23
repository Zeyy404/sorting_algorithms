#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *                    using bubble sorting algorithm
 * @array: the array of integers to be sorted
 * @size: the size of the array in concern
 * Returns: void
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	if (size < 2)
		print_array(array, size);

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
