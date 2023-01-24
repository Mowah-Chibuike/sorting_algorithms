#include "sort.h"
#include <stdio.h>

void swap(listint_t *a, listint_t *b, listint_t **list)
{
	if (a->prev != NULL)
		a->prev->next = b;
	b->prev = a->prev;
	if (b->next != NULL)
		b->next->prev = a;
	a->next = b->next;
	a->prev = b;
	b->next = a;
	if (b->prev == NULL)
		*list = b;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: double pointer to list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped, higher_count = 0;
	listint_t *head, *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = *list;
	while (head->next != NULL)
	{
		current = head;
		swapped = 0;
		while (current->next != NULL)
		{
			temp = current->next;
			if (current->n > temp->n)
			{
				swapped = 1;
				swap(current, temp, list);
				print_list(*list);
				current = temp;
			}
			if (current == NULL || current->prev == NULL)
				break;
			current = current->next;
		}
		current = current->prev;
		while (current != NULL && current->prev != NULL)
		{
			temp = current->prev;
			if (temp != NULL)
				if (current->n < temp->n)
				{
					swapped = 1;
					swap(temp, current, list);
					print_list(*list);
				}
			current = current->prev;
		}
		if (higher_count > 0 && swapped == 0)
			break;
		higher_count++;
		head = head->next;
	}
}
