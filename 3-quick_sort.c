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
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_s(array, 0, size - 1, size);
}

/**
 * quick_s - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @low: the low index of the array
 * @high: the high index of the array
 * @size: the size of the array
 *
 * Return: void
*/
void quick_s(int *array, int low, int high, size_t size)
{
	int pivot;

	/*Check whether there are more than one elements to sort*/
	if (low < high)
	{
		/*Partition the array to get the pivot*/
		pivot = lomuto_partition(array, low, high, size);
		/* Sort the left partition */
		quick_s(array, low, pivot - 1, size);
		/* Sort the right partition */
		quick_s(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions an array of integers
 * in ascending order using the Lomuto partition algorithm
 * @array: the array to be sorted
 * @low: the low index of the array
 * @high: the high index of the array
 * @size: the size of the array
 *
 * Return: the index of the pivot
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	/* Choose the pivot element as the last element of the array*/
	int pivot = array[high];
	int i = low;
	int j = low;

	/* Loop through the array*/
	for (; j < high; j++)
	{
		/* If the current element is less than  or equal with the pivot*/
		if (array[j] <= pivot)
		{
			/* Is the swap necessary? */
			if (j != i)
			{
				/* Swap and print the elements at i and j*/
				swapper(&array[i], &array[j]);
				print_array(array, size);
			}
			/* Increment i to move to the next position for potential swaps */
			i++;
		}
	}
	/* Check if pivot needs to be moved to its correct position*/
	if (i != high)
	{
		/* Move the pivot to its correct position*/
		swapper(&array[i], &array[high]);
		print_array(array, size);
	}

	/* Return the index of the pivot*/
	return (i);
}
