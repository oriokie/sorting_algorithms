#ifndef sort_h
#define sort_h

/* Importing Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structure for doubly linked list */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Provided print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swapper(int *a, int *b);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_s(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);


#endif/* sort_h */
