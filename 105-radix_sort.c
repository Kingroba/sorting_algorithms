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
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 *
 * Description: This function performs counting sort based on the specified significant digit.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buffer)
{
    int count[10] = {0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / sig) % 10] += 1;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--)
    {
        buffer[count[(array[i - 1] / sig) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / sig) % 10] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts the input array in ascending order
 *              using the LSD radix sort algorithm and prints the array
 *              after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    int max_val, sig, *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    max_val = find_max(array, size);
    for (sig = 1; max_val / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buffer);
        print_array(array, size);
    }

    free(buffer);
}

