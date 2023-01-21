#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pinter to the head node of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *hole, *next, *temp1, *temp2;
	int value;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	if (head->next == NULL)
		return;
	head = head->next;
	while (head != NULL)
	{
		value = head->n;
		hole = head;
		next = head->next;
		while (hole->prev != NULL && hole->prev->n > value)
		{
			temp1 = hole->prev;
			temp2 = hole->next;
			if (temp2 != NULL)
				temp2->prev = temp1;
			temp1->next = temp2;
			hole->prev = temp1->prev;
			if (temp1->prev != NULL)
				temp1->prev->next = hole;
			temp1->prev = hole;
			hole->next = temp1;
			if (hole->prev == NULL)
				*list = hole;
			print_list(*list);
		}
		head = next;
	}
}
