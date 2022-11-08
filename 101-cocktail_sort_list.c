#include "sort.h"

/**
 * swapNodes - swaps both nodes doubly-linked list.
 *
 * @list: list to set
 * @n1: node to swap
 * @n2: second node to swap.
 */
void swapNodes(listint_t *n1, listint_t *n2, listint_t **list)
{
	if (n1->prev == NULL)
	{
		n1->prev = n2->next;
		if (n2->next)
			n2->next->prev = n1;
		n2->next = n1;
		n2->prev = NULL;
		n1->prev = n2;
		*list = n2;
	}
	else
	{
		n2->prev->next = n2->next;
		if (n2->next)
			n2->next->prev = n2->prev;
		n1->prev->next = n2;
		n2->prev = n1->prev;
		n1->prev = n2;
		n2->next = n1;
	}
}
/**
 * cocktail_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * 
 * @list: doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curNode, *nextNode;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;

	curNode = (*list);
	do {
		swapped = 0;
		while (curNode->next)
		{
			nextNode = curNode->next;
			if (nextNode && curNode->n > nextNode->n)
			{
				swapNodes(curNode, nextNode, list);
				swapped = 1;
				print_list((*list));
			}
			else
				curNode = curNode->next;
		}
		curNode = curNode->prev;
		while (curNode->prev)
		{
			nextNode = curNode->prev;
			if (nextNode && curNode->n < nextNode->n)
			{
				swapNodes(nextNode, curNode, list);
				swapped = 1;
				print_list((*list));
			}
			else
				curNode = curNode->prev;
		}
		curNode = curNode->next;
	} while (swapped);
}
