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
 * max_heapify - Adjusts a binary tree into a max heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 *
 * Description: This function adjusts the binary tree rooted at 'root' to satisfy the max heap property.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;
	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < base && array[left] > array[largest])
		largest = left;

	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_integers(array + root, array + largest);
		print_array(array, size);
		max_heapify(array, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 *             using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function implements the heap sort algorithm
 *              using the sift-down approach and prints the array
 *              after each swap operation.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_integers(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}

