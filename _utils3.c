#include "monty.h"


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
* print_str - func to print string from a double linked list
* @h: pointer to head of node
*/
void print_str(const stack_t *h)
{
	while (h != NULL)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		putchar(h->n);
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
