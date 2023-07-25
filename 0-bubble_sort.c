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
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort.
 * @array: Pointer to the array of integers to sort.
 * @size: The number of elements in the array.
 *
 * Description: The function sorts the array using the Bubble Sort algorithm
 * and prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, len = size;
    bool swapped = false;

    if (array == NULL || size < 2)
        return;

    while (swapped == false)
    {
        swapped = true;
        for (i = 0; i < len - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_elements(array + i, array + i + 1);
                print_array(array, size);
                swapped = false;
            }
        }
        len--;
    }
}

