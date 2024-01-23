#include "sort.h"

/**
 * quicksort - recursive function for quick sort
 * @array: the array of integers to be sorted
 * @low: the low index of the current partition
 * @high: the high index of the current partition
 * @size: size of the array
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp, pi;
	if (low < high)
	{
		pivot = array[high];
		i = low - 1;

		for (j = low; j < high; j++)
		{
			if (array[j] < pivot)
			{
				i++;

				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}
		}

		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;

		print_array(array, size);

		pi = i + 1;

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order
 *                  using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Returns: void
 */
void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (size < 2)
		return;

	quicksort(array, low, high, size);
}
