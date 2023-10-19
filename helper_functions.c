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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;


	/** increment number of nodes*/
	number_nodes = number_nodes + 1;

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
	if (h == NULL)
	{
		; /** printf("====> Empty stack <======\n");*/
	}
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}



/**
* print_top - func to print data of a double linked list
* @h: pointer to head of node
*
* Return: number of nodes in the list
*/
void print_top(const stack_t *h)
{
	if (h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}





/**
* print_top_char - func to print the char at the top of a double linked list
* @h: pointer to head of node
*
* Return: number of nodes in the list
*/
void print_top_char(const stack_t *h)
{
	int data;

	if (h == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	data = h->n;

	if (data > 127 || data < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}
	else
	{
		putchar(data);
		putchar('\n');
	}

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
