#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: head of list
 * @n: value of new item
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	if (!head)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->n = n;
	current = *head;
	while (current)
	{
		if (current->next)
			current = current->next;
		else
		{
			current->next = new;
			break;
		}
	}
	new->prev = current;
	if (!*head)
		*head = new;
	return (new);
}
