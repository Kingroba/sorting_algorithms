#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @element1: Pointer to the first element to swap.
 * @element2: Pointer to the second element to swap.
 *
 * Description: Swaps the values of two elements in an array.
 */
void swap_elements(int *element1, int *element2)
{
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Description: The function sorts the array using the Selection Sort algorithm
 * and prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    int *min;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;
        for (j = i + 1; j < size; j++)
            min = (array[j] < *min) ? (array + j) : min;

        if ((array + i) != min)
        {
            swap_elements(array + i, min);
            print_array(array, size);
        }
    }
}

