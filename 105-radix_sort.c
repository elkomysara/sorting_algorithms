#include "sort.h"

/**
* get_max - Finds the maximum integer in an array.
* @array: The array of integers.
* @size: The size of the array.
*
* Return: The maximum integer.
*/
int get_max(int *array, size_t size)
{
int max = array[0];
size_t i;

for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
* counting_sort_radix - Sorts an array of integers using the Counting
*                       sort algorithm based on the digit represented
*                       by the current exponent.
* @array: The array of integers.
* @size: The size of the array.
* @exp: The exponent representing the current digit's place (1, 10, 100, etc.).
*/
void counting_sort_radix(int *array, size_t size, int exp)
{
int *output, count[10] = {0};
size_t i;

output = malloc(sizeof(int) * size);
if (!output)
return;

/* Store count of occurrences in count[] */
for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;

/* Change count[i] to hold the actual position of this digit in output[] */
for (i = 1; i < 10; i++)
count[i] += count[i - 1];

/* Build the output array */
for (i = size - 1; (int)i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

/* Copy the output array to array[], so that array now contains sorted numbers */
for (i = 0; i < size; i++)
array[i] = output[i];

print_array(array, size);
free(output);
}

/**
* radix_sort - Sorts an array of integers in ascending order using
*              the Radix sort algorithm.
* @array: The array of integers.
* @size: The size of the array.
*/
void radix_sort(int *array, size_t size)
{
int max, exp;

if (size < 2)
return;

max = get_max(array, size);

/* Perform counting sort for every digit, starting from the least significant digit */
for (exp = 1; max / exp > 0; exp *= 10)
counting_sort_radix(array, size, exp);
}
