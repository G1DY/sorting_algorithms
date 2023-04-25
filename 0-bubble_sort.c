#include "sort.h"
/**
 * swap_integers - swaps two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: 0 always success
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort
 * @array: array of integers
 * @size: size of the array
 *
 * Description: print the array after each time you swap two elements
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly == true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_integers(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
