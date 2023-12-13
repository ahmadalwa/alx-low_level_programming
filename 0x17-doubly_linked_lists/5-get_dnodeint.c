#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: head of list
 * @index: the index of the node, starting from 0
 *
 * Return: dlistint_t (if the node does not exist, return NULL)
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int  i;

	for (i = 0; i < index; i++)
	{
		if (head->next)
		{
			head = head->next;
		}
		else
		{
			head = NULL;
			break;
		}
	}
	return (head);
}
