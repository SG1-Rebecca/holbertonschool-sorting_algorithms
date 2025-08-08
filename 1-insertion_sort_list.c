#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *insert_pos;

	/* Check base cases */
	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next; /* Start with the second element */

	while (current)
	{
		next_node = current->next;  /* Save next node */
		insert_pos = current->prev; /* Potential insertion position */

		/* Find the correct position to insert current node */
		while (insert_pos && insert_pos->n > current->n)
			insert_pos = insert_pos->prev;

		/* If current node is already in correct position */
		if (insert_pos == current->prev)
		{
			current = next_node;
			continue;
		}

		/* Remove current node from its position */
		if (current->next)
			current->next->prev = current->prev;
		current->prev->next = current->next;

		/* Insert current node at the correct position */
		if (!insert_pos)
		{
			/* Insert at the beginning */
			current->prev = NULL;
			current->next = *list;
			(*list)->prev = current;
			*list = current;
		}
		else
		{
			/* Insert after insert_pos */
			current->prev = insert_pos;
			current->next = insert_pos->next;
			insert_pos->next->prev = current;
			insert_pos->next = current;
		}

		/* Print the list after each swap */
		print_list(*list);

		current = next_node;
	}
}
