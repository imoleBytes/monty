#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

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


/**
* sub_func - func sub top 2 ittems.
* @h: double pointer to the head of stack
*
*/
void sub_func(stack_t **h)
{
	stack_t *head = *h;
	int n1 = head->n;
	int n2 = head->next->n;
	int n = n2 - n1;

	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	push_to_stack(h, n);
}


/**
* div_func - func divide top 2 ittems.
* @h: double pointer to the head of stack
*
*/
void div_func(stack_t **h)
{
	stack_t *head = *h;
	int n1, n2, n;

	n1 = head->n;
	if (n1 == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
	n2 = head->next->n;
	n = n2 / n1;

	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	push_to_stack(h, n);
}


/**
* mul_func - func multiply top 2 ittems.
* @h: double pointer to the head of stack
*
*/
void mul_func(stack_t **h)
{
	stack_t *head = *h;
	int n1, n2, n;

	n1 = head->n;
	n2 = head->next->n;
	n = n2 * n1;

	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	push_to_stack(h, n);
}



/**
* mod_func - func finds the mod of top 2 ittems.
* @h: double pointer to the head of stack
*
*/
void mod_func(stack_t **h)
{
	stack_t *head = *h;
	int n1, n2, n;

	n1 = head->n;
	n2 = head->next->n;
	n = n2 % n1;

	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	push_to_stack(h, n);
}
