#include "monty.h"
#include <stdlib.h>


/**
 * add_dnodeint_end - func adds a new node at the end of a stack_t list
 * @head: double pointer to d head of the list
 * @n: data of the element
 * Return: the address of the new element or NULL if it failed
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *h = *head;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (h == NULL)
	{
		new->prev = h;
		*head = new;
		return (new);
	}

	while (h)	/* node1   node2   node3 NULL */
	{
		if (h->next == NULL)
		{
			h->next = new;
			new->prev = h;
			number_nodes++;
			return (new);
		}
		else
		{
			h = h->next;
		}
	}
	return (new);
}
