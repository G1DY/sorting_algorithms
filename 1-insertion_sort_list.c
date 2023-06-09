#include "sort.h"
/**
 * swap_nodes - swap two nodes of a doubly linked list of integers
 * @h: pointer to the head of the doubly linked list
 * @n1: first node to swap
 * @n2: second node to swap
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = (*n1);
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort
 * @list: pointer to the head of the doubly linked list
 *
 * Description: prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterate = (*list)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		insert = iterate->prev;
		while (insert != NULL && iterate->n < insert->n)
		{
			swap_nodes(list, &insert, iterate);
			print_list((const listint_t *)*list);
		}
	}
}
