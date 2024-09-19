#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node structure
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 *
 * Description: This structure is used for the doubly linked list
 * in sorting algorithms.
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes for sorting algorithms */

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 * @array: Pointer to the array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the Quick sort algorithm with Lomuto partitioning,
 * printing the array after every swap.
 */
void quick_sort(int *array, size_t size);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */
