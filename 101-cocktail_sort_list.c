#include "sort.h"

/**
* swap_nodes - Swap two nodes in a doubly linked list.
* @list: Pointer to the head of the doubly linked list.
* @left: The left node to swap.
* @right: The right node to swap.
*/
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left->prev)
left->prev->next = right;
else
*list = right;

if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;
right->next = left;
left->prev = right;

print_list(*list);
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
*                      order using the Cocktail shaker sort algorithm.
* @list: Pointer to the head of the list.
*/
void cocktail_sort_list(listint_t **list)
{
bool swapped = true;
listint_t *start = NULL, *end = NULL;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (swapped)
{
swapped = false;
start = *list;

/* Traverse from left to right */
while (start->next != end)
{
if (start->n > start->next->n)
{
swap_nodes(list, start, start->next);
swapped = true;
}
start = start->next;
}

if (!swapped)
break;

swapped = false;
end = start;

/* Traverse from right to left */
while (start->prev != NULL)
{
if (start->n < start->prev->n)
{
swap_nodes(list, start->prev, start);
swapped = true;
}
start = start->prev;
}
}
}
