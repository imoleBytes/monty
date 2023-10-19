#include "monty.h"



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



/**
 * delete_dnodeint_at_index - deletes node at index of a double linked list
 *
 * @head: double pointer to head of the list
 * @index: index of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *head_1;
	stack_t *head_2;
	unsigned int i;

	head_1 = *head;

	if (head_1 != NULL)
		while (head_1->prev != NULL)
			head_1 = head_1->prev;

	i = 0;

	while (head_1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = head_1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				head_2->next = head_1->next;

				if (head_1->next != NULL)
					head_1->next->prev = head_2;
			}

			free(head_1);
			/** decrement of number of node*/
			number_nodes = number_nodes - 1;
			return (1);
		}
		head_2 = head_1;
		head_1 = head_1->next;
		i++;
	}
	return (-1);
}
