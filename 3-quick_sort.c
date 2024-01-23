#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * and returns the partition index
 * @array: the array of integers to be sorted
 * @low: the low index of the current partition
 * @high: the high index of the current partition
 * @size: the size of the array
 * Return: the partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{

			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}

			i++;
		}
	}

	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i);
}

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
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

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
