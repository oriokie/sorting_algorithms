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
 * selection_sort - Sorts an array of integers in ascending order
 * and prints the array after each swap
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* Assume the min number is the first element in the array */
		min_index = i;
		/* Find the min number in the array after i position */
		for (j = i + 1; j < size; j++)
		{
			/* if the element is less, then it is the new minimum*/
			if (array[j] < array[min_index])
			{
				/* Update the min_index to the new minimum position*/
				min_index = j;
				continue;
			}
		}
		if (min_index != i)
		{
			swapper(&array[i], &array[min_index]);
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
