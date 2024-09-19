#include "sort.h"

/**
* swap_ints - Swap two integers in an array.
* @a: The first integer to swap.
* @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* bitonic_merge - Recursively sorts a bitonic sequence in a specified direction.
* @array: The array of integers to sort.
* @low: The starting index of the sequence in array to sort.
* @cnt: The size of the sequence to sort.
* @dir: The direction to sort in (1 for ascending, 0 for descending).
*/
void bitonic_merge(int *array, int low, int cnt, int dir)
{
int i, k;

if (cnt > 1)
{
k = cnt / 2;
for (i = low; i < low + k; i++)
{
if ((dir == 1 && array[i] > array[i + k]) ||
(dir == 0 && array[i] < array[i + k]))
swap_ints(&array[i], &array[i + k]);
}
bitonic_merge(array, low, k, dir);
bitonic_merge(array, low + k, k, dir);
}
}

/**
* bitonic_sort_recursion - Builds a bitonic sequence and sorts it recursively.
* @array: The array of integers to sort.
* @low: The starting index of the sequence.
* @cnt: The size of the sequence.
* @dir: The direction to sort in (1 for ascending, 0 for descending).
* @size: The total size of the array.
*/
void bitonic_sort_recursion(int *array, int low, int cnt, int dir, size_t size)
{
int k;

if (cnt > 1)
{
k = cnt / 2;

printf("Merging [%d/%lu] (%s):\n", cnt, size,
(dir == 1) ? "UP" : "DOWN");
print_array(array + low, cnt);

bitonic_sort_recursion(array, low, k, 1, size); /* Sort in ascending */
bitonic_sort_recursion(array, low + k, k, 0, size); /* Sort in descending */

bitonic_merge(array, low, cnt, dir);

printf("Result [%d/%lu] (%s):\n", cnt, size,
(dir == 1) ? "UP" : "DOWN");
print_array(array + low, cnt);
}
}

/**
* bitonic_sort - Sorts an array of integers in ascending order
*                using the Bitonic sort algorithm.
* @array: The array of integers.
* @size: The size of the array.
*/
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

bitonic_sort_recursion(array, 0, size, 1, size);
}
