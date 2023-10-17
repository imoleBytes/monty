#include "monty.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * push_to_stack - func adds a new node at d beginning of a stack_t list
 * @head: double pointer to d head of the list
 * @n: data of the element
 * Return: the address of the new element or NULL if it failed
 */
stack_t *push_to_stack(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *h = *head; /* adddress of the head node now h */

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->prev = NULL;

	if (h != NULL)
	{
		while (h->prev != NULL)
		{
			h = h->prev;
		}
	}

	new->next = h; /* or h */
	if (h != NULL)
	{
		h->prev = new;
	}
	*head = new;

	return (new);
}



/**
* print_stack - func to print data of a double linked list
* @h: pointer to head of node
*
* Return: number of nodes in the list
*/
void print_stack(const stack_t *h)
{
	// size_t count = 0;
	if (h == NULL)
		printf("empty stack\n");

	while (h != NULL)
	{
		printf("%d\n", h->n);
		// count++;
		h = h->next;

	}
	// return (count);
}
