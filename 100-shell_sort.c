#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order using
*              the Shell sort algorithm, using the Knuth sequence.
* @array: The array of integers.
* @size: The size of the array.
*
* Description: Uses the Knuth sequence to determine the interval.
*/
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
int temp;

if (array == NULL || size < 2)
return;

/* Start with the largest gap from the Knuth sequence */
gap = 1;
while (gap < size / 3)
gap = gap * 3 + 1;

while (gap >= 1)
{
for (i = gap; i < size; i++)
{
temp = array[i];
for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
array[j] = array[j - gap];
array[j] = temp;
}
print_array(array, size);
gap /= 3; /* Reduce the gap */
}
}
