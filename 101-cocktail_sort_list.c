#include "sort.h"

/**
* swap_nodes - Swap two adjacent nodes in a doubly linked list.
* @list: Pointer to the head of the doubly linked list.
* @left: The left node to swap.
* @right: The right node to swap.
*/
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left == NULL || right == NULL)
return;

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
bool swapped;
listint_t *start, *end;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

swapped = true;
end = NULL;

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
else
{
start = start->next;
}
}
end = start;

if (!swapped)
break;

swapped = false;

/* Traverse from right to left */
while (start->prev != NULL)
{
if (start->n < start->prev->n)
{
swap_nodes(list, start->prev, start);
swapped = true;
}
else
{
start = start->prev;
}
}
}
}
