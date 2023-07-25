#include "sort.h"

/**
 * find_max - Find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 *
 * Description: This function finds the maximum integer in the given array.
 */
int find_max(int *array, int size)
{
    int max_val = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max_val)
            max_val = array[i];
    }
    return max_val;
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function performs counting sort on the given array.
 *              It prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array, max_val;

    if (array == NULL || size < 2)
        return;

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
        return;

    max_val = find_max(array, size);
    count_array = malloc(sizeof(int) * (max_val + 1));
    if (count_array == NULL)
    {
        free(sorted_array);
        return;
    }

    /* Initialize the counting array */
    for (int i = 0; i <= max_val; i++)
        count_array[i] = 0;

    /* Count the occurrences of each element in the array */
    for (int i = 0; i < (int)size; i++)
        count_array[array[i]] += 1;

    /* Update the counting array to contain the actual positions of elements in the sorted array */
    for (int i = 1; i <= max_val; i++)
        count_array[i] += count_array[i - 1];

    /* Print the counting array */
    print_array(count_array, max_val + 1);

    /* Build the sorted array using the counting array */
    for (int i = size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]] -= 1;
    }

    /* Copy the sorted array back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(count_array);
}

