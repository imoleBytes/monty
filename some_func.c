#include "monty.h"

// tto swap
// check the len of node, if 2 or morre:
	// delete top
	// insert to index 1
// else, print cannot swap, too short.

void swap_nodes(stack_t **h)
{
	stack_t *head = *h;
	int n = head->n;

	delete_dnodeint_at_index(h, 0);
	insert_to_idx_1(h, 1, n);
}
