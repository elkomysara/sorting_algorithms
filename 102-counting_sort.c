#include "sort.h"
#include <stdlib.h>

/**
* counting_sort - Sorts an array of integers in ascending order
*                 using the Counting sort algorithm.
* @array: The array to sort.
* @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
int *count, *output, max, i;
size_t j;

if (array == NULL || size < 2)
return;

/* Find the maximum value in the array */
max = array[0];
for (j = 1; j < size; j++)
{
if (array[j] > max)
max = array[j];
}

/* Allocate memory for count array and output array */
count = malloc(sizeof(int) * (max + 1));
if (count == NULL)
return;

output = malloc(sizeof(int) * size);
if (output == NULL)
{
free(count);
return;
}

/* Initialize count array to 0 */
for (i = 0; i <= max; i++)
count[i] = 0;

/* Store the count of each element in count array */
for (j = 0; j < size; j++)
count[array[j]]++;

/* Modify count array so that each element indicates the position */
for (i = 1; i <= max; i++)
count[i] += count[i - 1];

/* Build the output array */
for (j = size; j > 0; j--)
{
output[count[array[j - 1]] - 1] = array[j - 1];
count[array[j - 1]]--;
}

/* Copy the output array back to the original array */
for (j = 0; j < size; j++)
array[j] = output[j];

/* Print the counting array */
print_array(count, max + 1);

free(count);
free(output);
}
