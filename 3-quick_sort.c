#include "sort.h"

/**
* swap - Swap two elements in the array.
* @a: first element
* @b: second element
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* partition - Lomuto partition scheme for quicksort
* @array: array of integers
* @low: starting index of partition
* @high: ending index of partition
* @size: size of the array
*
* Return: partition index
*/
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
    swap(&array[i], &array[j]);
    print_array(array, size);
}
}
}
if (i + 1 != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
* quicksort - Recursive quicksort function
* @array: array of integers
* @low: starting index of partition
* @high: ending index of partition
* @size: size of the array
*/
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
* quick_sort - Sorts an array using the Quick sort algorithm
* @array: array of integers
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
if (size < 2)
return;
quicksort(array, 0, size - 1, size);
}
