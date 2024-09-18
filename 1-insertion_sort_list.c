#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @left: Pointer to the node on the left to swap
 * @right: Pointer to the node on the right to swap
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
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *tmp;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
		current = next;
	}
}
