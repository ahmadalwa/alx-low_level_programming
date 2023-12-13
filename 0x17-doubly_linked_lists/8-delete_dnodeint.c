#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at index index
 *   of a dlistint_t linked list
 * @head: head of list
 * @index: is the index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur;
	unsigned int i;

	if (!head)
		return (-1);

	cur = *head;
	if (!cur)
		return (-1);
	for (i = 0; i < index; i++)
	{
		if (cur->next)
			cur = cur->next;
		else
		{
			cur = NULL;
			break;
		}
	}
	if (!cur)
		return (-1);

	if (cur->prev)
		cur->prev->next = cur->next;
	if (cur->next)
		cur->next->prev = cur->prev;
	if (index == 0)
		*head = cur->next;
	free(cur);
	return (1);
}
