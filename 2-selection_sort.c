#include "sort.h"
/**
 * swap_ints - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: An array of integers
 * @size: size of the array
 *
 * Description: prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + 1;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min)
			{
				min = array + j;
			}
			if ((array + i) != min)
			{
				swap_ints(array + i, min);
				print_array(array, size);
			}
		}
	}
}
