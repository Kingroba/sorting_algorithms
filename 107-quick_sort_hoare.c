#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 *
 * Description: This function swaps the integers pointed to by a and b.
 */
void swap_integers(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Partition a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 *
 * Description: This function uses the last element of the subset as the pivot.
 * It partitions the subset into two parts, one with elements less than the pivot
 * and the other with elements greater than the pivot.
 * The function prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
    int pivot, up, down;

    pivot = array[right];
    for (up = left - 1, down = right + 1; up < down;)
    {
        do
        {
            up++;
        } while (array[up] < pivot);
        do
        {
            down--;
        } while (array[down] > pivot);

        if (up < down)
        {
            swap_integers(array + up, array + down);
            print_array(array, size);
        }
    }

    return up;
}

/**
 * hoare_sort_recursive - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 *
 * Description: This function uses the Hoare partition scheme to sort the array recursively.
 */
void hoare_sort_recursive(int *array, size_t size, int left, int right)
{
    int partition_index;

    if (right - left > 0)
    {
        partition_index = hoare_partition(array, size, left, right);
        hoare_sort_recursive(array, size, left, partition_index - 1);
        hoare_sort_recursive(array, size, partition_index, right);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function uses the Hoare partition scheme
 * to sort the array and prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_sort_recursive(array, size, 0, size - 1);
}

