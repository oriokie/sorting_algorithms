#include "sort.h"

/**
 * node_swap - Swaps two nodes in a doubly linked list
 * @list: A pointer to the head of the doubly linked list
 * @current: A pointer to the current node to be swapped
*/
void node_swap(listint_t **list, listint_t *current)
{
	listint_t *prev_node, *next_node;

	prev_node = current->prev;
	next_node = current->next;

	current->next = prev_node;

	if (prev_node)
		current->prev = prev_node->prev;
	else
		current->prev = NULL;

	prev_node->next = next_node;

	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	if (next_node)
		next_node->prev = current;
	prev_node->prev = next_node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: A pointer to the head of the doubly linked list
 *
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	temp = (*list)->next;

	while (temp)
	{
		current = temp;
		temp = temp->next;
		while ((current->prev) && (current->n < current->prev->n))
		{
			node_swap(list, current);
			print_list(*list);
		}
	}
}
