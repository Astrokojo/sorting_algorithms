#include "sort.h"
/**
 * swap_node - Swaps two nodes in a list
 * @head: the head
 * @node1: the first node
 * @node2: the second node
 */
void swap_node(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = *node1;
		node2->prev = (*node1)->prev;
		node2->next = *node1;
		if ((*node1)->prev != NULL)
			(*node1)->prev->next = node2;
		else
			*head = node2;
		(*node1)->prev = node2;
		*node1 = node2->prev;
}

/**
 * insertion_sort_list - uses insert sort to sort doubly
 *		linked lists of integers in ascending order.
 * @list: pointer to doubly linked list.
 *
 * Returns: Prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;

		while (insert != NULL && iter->n < insert->n)
		{
			swap_node(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
