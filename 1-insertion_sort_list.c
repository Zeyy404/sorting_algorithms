#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *       in ascending order using the insertion sort algorithm
 * @list: a pointer to a pointer to head of the doubly linked list in concern
 * Returns: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp, *tempPrev, *tempNext;

	if (*list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			tempPrev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;
			if (current->next != NULL)
				current->next->prev = temp;
			if (temp->next == current)
			{
				temp->next = current->next;
				current->prev = temp->prev;
				current->next = temp;
				temp->prev = current;
			}
			else
			{
				tempNext = current->next;
				current->next = temp->next;
				temp->next = tempNext;
				if (tempNext != NULL)
					tempNext->prev = temp;
				if (current->next != NULL)
					current->next->prev = current;
				temp->prev = current;
			}
			temp = tempPrev;
			print_list(*list);
		}
		current = next;
	}
}
