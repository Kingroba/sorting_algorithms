#include "sort.h"

/**
 * swap_list_nodes - Swap two nodes in a doubly linked list.
 * @head: A pointer to the head of the doubly linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: A pointer to the second node to swap.
 *
 * Description: Swaps the positions of two nodes in a doubly linked list.
 */
void swap_list_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
    (*node1)->next = node2->next;
    if (node2->next != NULL)
        node2->next->prev = *node1;
    node2->prev = (*node1)->prev;
    node2->next = *node1;

    if ((*node1)->prev != NULL)
        (*node1)->prev->next = node2;
    else
        *head = node2;

    (*node1)->prev = node2;
    *node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly linked list of integers.
 *
 * Description: Sorts the doubly linked list using the Insertion Sort algorithm
 * and prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *iterator, *insertion, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (iterator = (*list)->next; iterator != NULL; iterator = tmp)
    {
        tmp = iterator->next;
        insertion = iterator->prev;

        while (insertion != NULL && iterator->n < insertion->n)
        {
            swap_list_nodes(list, &insertion, iterator);
            print_list((const listint_t *)*list);
        }
    }
}

