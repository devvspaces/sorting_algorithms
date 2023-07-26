#include "sort.h"

/**
 * swap_nodes - swaps two nodes
 *
 * @head: the head node
 *
 * @node1: The first node
 * @node2: the second node
 *
 * Return: void
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list with
 * the insertion sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node && node->prev; node = node->next)
	{
		for (; node && node->prev && node->n < node->prev->n;
			 node = node->prev)
		{
			tmp = node->prev;
			swap_nodes(list, tmp, node);
			print_list(*list);
			node = node->next;
		}
	}
}
