#include "sort.h"

/**
 * swap_elements - Swap two integers in an array.
 * @element1: Pointer to the first integer to swap.
 * @element2: Pointer to the second integer to swap.
 */
void swap_elements(int *element1, int *element2)
{
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

/**
 * lomuto_partition - Partition a subset of an array of integers using
 *                    the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 *
 * Description: Partitions the array such that elements less than the pivot
 * are on the left side, and elements greater than the pivot are on the right side.
 * Prints the array after each swap of two elements during the partitioning process.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, up, down;

    pivot = array + right;
    for (up = down = left; down < right; down++)
    {
        if (array[down] < *pivot)
        {
            if (up < down)
            {
                swap_elements(array + down, array + up);
                print_array(array, size);
            }
            up++;
        }
    }

    if (array[up] > *pivot)
    {
        swap_elements(array + up, pivot);
        print_array(array, size);
    }

    return up;
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 *
 * Description: Uses the Lomuto partition scheme to sort the array recursively.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int partition;

    if (right - left > 0)
    {
        partition = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, partition - 1);
        lomuto_sort(array, size, partition + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using
 *              the quicksort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme to perform the quicksort.
 * Prints the array after each swap of two elements during the sorting process.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

