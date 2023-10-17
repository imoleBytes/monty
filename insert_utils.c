#include "monty.h"
#include <stdlib.h>



/**
* dlistint_len - func to find the number of nodes in a double linked list
* @h: pointer to head of node
*
* Return: number of nodes in the list
*/
size_t dlistint_len(const stack_t *h)
{
	size_t count = 0;

	while (h != NULL) /* or while (h) */
	{
		count++;
		h = h->next;
	}
	return (count);
}



/**
 * insert_to_idx_1 - func to insert a new node at a specific
 * index of a double linked list
 * @h: double pointer to d head of the list
 * @idx: index
 * @n: data of the node to be inserted
 * Return: the address of the new node or NULL if it failed
 */
stack_t *insert_to_idx_1(stack_t **h, unsigned int idx, int n)
{
	stack_t *head = *h;
	stack_t *new;
	unsigned int i = 0;

	new = malloc(sizeof(stack_t));
	if (*h == NULL && idx == 0)
	{
		new = push_to_stack(h, n);
		return (new);
	}
	if (new == NULL)
		return (NULL);
	while (head->prev != NULL)
		head = head->prev;

	if (idx == 0)
	{
		new = push_to_stack(h, n);
		return (new);
	}
	
	if (idx == dlistint_len(*h))
	{
		new = add_dnodeint_end(h, n);
		return (new);
	}
	
	while (head != NULL)
	{
		if (i == idx)
		{
			new->n = n;
			new->prev = head->prev;
			head->prev->next = new;
			new->next = head;
			head->prev = new;
			number_nodes++;
			return (new);
		}
		i++;
		head = head->next;
	}
	return (NULL);
}
