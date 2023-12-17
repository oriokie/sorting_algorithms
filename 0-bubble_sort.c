#include "sort.h"

/**
 * swapper - Swaps two integers
 * @a: int 1
 * @b: int 2
 *
 * Return: void
*/
void swapper(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * and prints the array after each swap
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapper(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
