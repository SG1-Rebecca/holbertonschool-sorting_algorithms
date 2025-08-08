#include "sort.h"
/**
* bubble_sort - sorts an array of integers in ascending order
*@array: Array of integers
*@size: Size of the arrays
*
* Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
size_t round, index;
int tmp;
/* if array is empty or size has less than 2 elements*/
if (array == NULL || size < 2)
{
return;
}
for (round = 0; round < size - 1; round++)
{
for (index = 0; index < size - 1 - round; index++)
{
if (array[index] > array[index + 1])
{
tmp = array[index];
array[index] = array[index + 1];
array[index + 1] = tmp;
print_array(array, size);
}
}
}
}
