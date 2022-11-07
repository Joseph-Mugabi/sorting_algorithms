#include "sort.h"

/**
 * swapNodes - swap two nodes in a listint_t doubly-linked list.
 *
 * @head: pointer to the head of the doubly-linked list.
 * @node: pointer to the first node to swap.
 * @node1: the second node to swap.
 */
void swapNodes(listint_t **head, listint_t **node, listint_t *node1)
{
	(*node)->next = node1->next;
	if (node1->next != NULL)
		node1->next->prev = *node;
	node1->prev = (*node)->prev;
	node1->next = *node;
	if ((*node)->prev != NULL)
		(*node)->prev->next = node1;
	else
		*head = node1;
	(*node)->prev = node1;
	*node = node1->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 *
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *insert, *i;

	if (!list || !(*list) || !(*list)->next)
		return;

	for (i = (*list)->next; i != NULL; i = tmp)
	{
		tmp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swapNodes(list, &insert, i);
			print_list((listint_t *)*list);
		}
	}
}
