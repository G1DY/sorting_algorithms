#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integers
 * @a: First integer
 * @b: Second Integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - assumes the pivot element to be last element
 * @array: The array of integers
 * @size: The Size of the array
 * @left: starting index of the sublist
 * @right: ending index of the sublist
 *
 * Return: The final index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, partition1, partition2;

	pivot = array + right;
	for (partition1 = partition2 = left; partition2 < right; partition2++)
	{
		if (array[partition2] < *pivot)
		{
			if (partition1 < partition2)
			{
				swap_ints(array + partition2, array + partition1);
				print_array(array, size);
			}
			partition1++;
		}
	}
	if (array[partition1] > *pivot)
	{
		swap_ints(array + partition1, pivot);
		print_array(array, size);
	}
	return (partition1);
}

/**
 * lomuto_sort - implements the lomuto function
 * @array: array of integers
 * @size: size of the array
 * @left: index start of the partition
 * @right: index end of the partion
 *
 * Description: implements lomuto scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts the array in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Prints array after each swap using lomuto
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
