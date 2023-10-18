#include "monty.h"

/**
* swap_nodes - func swaps.
* @h: double pointer to the head of stack
*
*/

void swap_nodes(stack_t **h)
{
	stack_t *head = *h;
	int n = head->n;

	delete_dnodeint_at_index(h, 0);
	insert_to_idx_1(h, 1, n);
}


/**
* add_func - func add top 2 ittems.
* @h: double pointer to the head of stack
*
*/
void add_func(stack_t **h)
{
	stack_t *head = *h;
	int n1 = head->n;
	int n2 = head->next->n;
	int n = n1 + n2;

	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	push_to_stack(h, n);
}
