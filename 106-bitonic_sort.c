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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in the array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 *
 * Description: This function performs the bitonic merge operation on a bitonic sequence.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t i, jump = seq / 2;

    if (seq > 1)
    {
        for (i = start; i < start + jump; i++)
        {
            if ((flow == 'U' && array[i] > array[i + jump]) ||
                (flow == 'D' && array[i] < array[i + jump]))
                swap_integers(array + i, array + i + jump);
        }
        bitonic_merge(array, size, start, jump, flow);
        bitonic_merge(array, size, start + jump, jump, flow);
    }
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 *
 * Description: This function converts an array into a bitonic sequence.
 *              It recursively divides the array into smaller bitonic sequences
 *              and then merges them to obtain the final bitonic sequence.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq, char flow)
{
    size_t cut = seq / 2;
    const char *str = (flow == 'U') ? "UP" : "DOWN";

    if (seq > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);

        bitonic_sequence(array, size, start, cut, 'U');
        bitonic_sequence(array, size, start + cut, cut, 'D');
        bitonic_merge(array, size, start, seq, flow);

        printf("Result [%lu/%lu] (%s):\n", seq, size, str);
        print_array(array + start, seq);
    }
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *                using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts the input array using the bitonic sort algorithm.
 *              It only works for arrays of size 2^k where k >= 0 (i.e., powers of 2).
 *              The function prints the array after each swap operation.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sequence(array, size, 0, size, 'U');
}

