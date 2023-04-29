#include "sort.h"
/**
 * swap_ints - swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * shell_sort - array of integers in ascending order
 *              using the Shell sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: uses knuth sequence
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, part1, part2;

    if (array == NULL || size < 2)
        return;
    for (gap = 1; gap < (size / 3);)
        gap = gap * 3 + 1;
    for (; gap >= 1; gap /= 3)
    {
        for (part1 = gap; part1 < size; part1++)
        {
            part2 = part1;
            while (part2 >= gap && array[part2 - gap] > array[part2])
            {
                swap_ints(array + part2, array + (part2 - gap));
                part2 -= gap;
            }
        }
        print_array(array, size);
    }
}
