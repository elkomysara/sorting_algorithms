#include "sort.h"

/**
* swap_ints - Swap two integers in an array.
* @a: The first integer.
* @b: The second integer.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* heapify - Create a max heap from an unsorted array.
* @array: The array of integers.
* @size: The size of the array.
* @root: The root index.
* @total_size: The total size of the array (for printing purposes).
*/
void heapify(int *array, size_t size, size_t root, size_t total_size)
{
size_t largest = root;
size_t left = 2 * root + 1;
size_t right = 2 * root + 2;

if (left < size && array[left] > array[largest])
largest = left;

if (right < size && array[right] > array[largest])
largest = right;

if (largest != root)
{
swap_ints(&array[root], &array[largest]);
print_array(array, total_size);
heapify(array, size, largest, total_size);
}
}

/**
* heap_sort - Sort an array of integers in ascending order
*             using the Heap sort algorithm.
* @array: The array of integers.
* @size: The size of the array.
*/
void heap_sort(int *array, size_t size)
{
int i;

if (size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
heapify(array, size, i, size);

for (i = size - 1; i > 0; i--)
{
swap_ints(&array[0], &array[i]);
print_array(array, size);
heapify(array, i, 0, size);
}
}
