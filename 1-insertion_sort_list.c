#include "sort.h"

/**
 * swap_nodes - swaps the nodes in a doubly linked list
 * @list: the doubly linked list
 * @node1: the first node
 * @node2: the second node
 *
 * Return: void
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!list || !node1 || !node2 || node1->next != node2)
	{
		return;
	}

	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	if (node2->next)
	{
		node2->next->prev = node1;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: the doubly linked list
 *
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_iter;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	current = (*list)->next;

	while (current)
	{
		next_iter = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		current = next_iter;
	}
}
