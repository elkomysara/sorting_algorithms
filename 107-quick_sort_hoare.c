#include "sort.h"

/**
* swap - Swaps two elements in an array.
* @a: The first element.
* @b: The second element.
*/
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
* hoare_partition - Partitions the array using Hoare's scheme.
* @array: The array to partition.
* @low: The starting index.
* @high: The ending index.
* @size: The size of the array.
*
* Return: The partition index.
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
int pivot = array[low];
int left = low - 1;
int right = high + 1;

while (1)
{
do {
left++;
} while (array[left] < pivot);

do {
right--;
} while (array[right] > pivot);

if (left >= right)
return right;

swap(&array[left], &array[right]);
print_array(array, size);
}
}

/**
* hoare_sort - Recursively sorts the array using Hoare's partition scheme.
* @array: The array to sort.
* @low: The starting index.
* @high: The ending index.
* @size: The size of the array.
*/
void hoare_sort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int partition_index = hoare_partition(array, low, high, size);
hoare_sort(array, low, partition_index, size);
hoare_sort(array, partition_index + 1, high, size);
}
}

/**
* quick_sort_hoare - Sorts an array of integers using Quick sort (Hoare's scheme).
* @array: The array to sort.
* @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (size < 2)
return;

hoare_sort(array, 0, size - 1, size);
}
