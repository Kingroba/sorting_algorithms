#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current_node_ahead);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current_node_behind);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a doubly-linked list of integers
 *                   with the node ahead of it.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current_node_ahead: A pointer to the current node being swapped with the one ahead of it.
 *
 * Description: This function swaps the current_node_ahead with the node ahead of it
 *              in the doubly-linked list.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current_node_ahead)
{
    listint_t *tmp = (*current_node_ahead)->next;

    if ((*current_node_ahead)->prev != NULL)
        (*current_node_ahead)->prev->next = tmp;
    else
        *list = tmp;

    tmp->prev = (*current_node_ahead)->prev;
    (*current_node_ahead)->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = *current_node_ahead;
    else
        *tail = *current_node_ahead;

    (*current_node_ahead)->prev = tmp;
    tmp->next = *current_node_ahead;
    *current_node_ahead = tmp;
}

/**
 * swap_node_behind - Swap a node in a doubly-linked list of integers
 *                    with the node behind it.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current_node_behind: A pointer to the current node being swapped with the one behind it.
 *
 * Description: This function swaps the current_node_behind with the node behind it
 *              in the doubly-linked list.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current_node_behind)
{
    listint_t *tmp = (*current_node_behind)->prev;

    if ((*current_node_behind)->next != NULL)
        (*current_node_behind)->next->prev = tmp;
    else
        *tail = tmp;

    tmp->next = (*current_node_behind)->next;
    (*current_node_behind)->prev = tmp->prev;

    if (tmp->prev != NULL)
        tmp->prev->next = *current_node_behind;
    else
        *list = *current_node_behind;

    (*current_node_behind)->next = tmp;
    tmp->prev = *current_node_behind;
    *current_node_behind = tmp;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of the doubly-linked list.
 *
 * Description: This function implements the cocktail shaker sorting algorithm
 *              for a doubly-linked list of integers in ascending order.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *current_node;
    bool swapped = false;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL;)
        tail = tail->next;

    while (swapped == false)
    {
        swapped = true;

        for (current_node = *list; current_node != tail; current_node = current_node->next)
        {
            if (current_node->n > current_node->next->n)
            {
                swap_node_ahead(list, &tail, &current_node);
                print_list((const listint_t *)*list);
                swapped = false;
            }
        }

        for (current_node = current_node->prev; current_node != *list; current_node = current_node->prev)
        {
            if (current_node->n < current_node->prev->n)
            {
                swap_node_behind(list, &tail, &current_node);
                print_list((const listint_t *)*list);
                swapped = false;
            }
        }
    }
}

