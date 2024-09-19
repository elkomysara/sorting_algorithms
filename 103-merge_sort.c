#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* merge - Merges two sub-arrays of integers in sorted order.
* @array: The array to sort.
* @left: The left sub-array.
* @right: The right sub-array.
* @size_left: The size of the left sub-array.
* @size_right: The size of the right sub-array.
*/
void merge(int *array, int *left, int *right, size_t size_left, size_t size_right)
{
size_t i = 0, j = 0, k = 0;

printf("Merging...\n[left]: ");
print_array(left, size_left);
printf("[right]: ");
print_array(right, size_right);

while (i < size_left && j < size_right)
{
if (left[i] <= right[j])
{
array[k++] = left[i++];
}
else
{
array[k++] = right[j++];
}
}

while (i < size_left)
array[k++] = left[i++];

while (j < size_right)
array[k++] = right[j++];

printf("[Done]: ");
print_array(array, size_left + size_right);
}

/**
* merge_sort - Sorts an array of integers in ascending order
*              using the Merge sort algorithm (top-down).
* @array: The array to sort.
* @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
size_t mid, i;
int *left, *right;

if (size < 2)
return;

mid = size / 2;

left = malloc(mid * sizeof(int));
if (!left)
return;

right = malloc((size - mid) * sizeof(int));
if (!right)
{
free(left);
return;
}

for (i = 0; i < mid; i++)
left[i] = array[i];
for (i = mid; i < size; i++)
right[i - mid] = array[i];

merge_sort(left, mid);
merge_sort(right, size - mid);

merge(array, left, right, mid, size - mid);

free(left);
free(right);
}
