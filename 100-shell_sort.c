#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: Pointer to the first integer to swap.
 * @y: Pointer to the second integer to swap.
 *
 * Description: This function swaps the integers pointed to by x and y.
 */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the shell sort algorithm.
 * @arr: Pointer to the array of integers.
 * @size: The size of the array.
 *
 * Description: This function implements the shell sort algorithm
 *              with the Knuth interval sequence.
 */
void shell_sort(int *arr, size_t size)
{
    size_t gap, i, j;

    if (arr == NULL || size < 2)
        return;

    /* Calculate the initial gap using Knuth interval sequence */
    for (gap = 1; gap < (size / 3);)
        gap = gap * 3 + 1;

    /* Perform shell sort with decreasing gaps */
    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            j = i;
            while (j >= gap && arr[j - gap] > arr[j])
            {
                swap(&arr[j], &arr[j - gap]);
                j -= gap;
            }
        }
        print_array(arr, size);
    }
}

