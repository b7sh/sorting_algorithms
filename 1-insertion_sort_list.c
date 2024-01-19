#include "sort.h"

/**
 * nodes_swap - function to swap two nodes
 * @head: the head of the list
 * @first_head: the head of the first node
 * @second_head: the head of the second node
*/

void nodes_swap(listint_t **head, listint_t **first_head,
			listint_t *second_head)
{
	(*first_head)->next = second_head->next;
	if (second_head->next != NULL)
		second_head->next->prev = *first_head;
	second_head->prev = (*first_head)->prev;
	second_head->next = *first_head;
	if ((*first_head)->prev != NULL)
		(*first_head)->prev->next = second_head;
	else
		*head = second_head;
	(*first_head)->prev = second_head;
	*first_head = second_head->prev;
}

/**
 * insertion_sort_list - function to sort lists
 * @list: the head of the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *add, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iterate = (*list)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		add = iterate->prev;
		while (add != NULL && iterate->n < add->n)
		{
			nodes_swap(list, &add, iterate);
			print_list((const listint_t *)*list);
			add = iterate->prev;
		}
	}
}
