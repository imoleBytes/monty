#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int number_nodes = 0;

int main(void)
{
	stack_t *stack;
	int choice, data;

	stack = NULL;

	while(1)
	{
		printf("There are %d nodes now in the stack!\n", number_nodes);

		// printf("Select Choices\n\n");
		printf("1. push to stack\n2. Print first node\n3. delete top\n4. list the stack\n5. swap\n6. exit\n");
		printf("Select Choice: ");
		scanf("%d", &choice);


		switch (choice)
		{
			case 1:
				printf("Enter data to be inserted (int): ");
				scanf("%d", &data);
				push_to_stack(&stack, data);
				break;
			case 2:
				print_top(stack);
				break;
			case 3:
				printf("delete top of stack\n");
				if (delete_dnodeint_at_index(&stack, 0) == -1)
				{
					printf("L<line_number>: can't pop an empty stack\n");
					exit(EXIT_FAILURE);
				}
				break;
			case 4:
				print_stack(stack);
				break;
			case 5:
				if (number_nodes < 2)
				{
					printf("L<line_number>: can't swap, stack too short\n");
					exit(EXIT_FAILURE);
				}
				else
					swap_nodes(&stack);
				break;
			case 6:				
				printf("Exited!\n");
				exit(98);
			default:
				printf("Invalid choice\n");
		}
	}

	return (0);
}



// tto swap
// check the len of node, if 2 or morre:
	// delete top
	// insert to index 1
// else, print cannot swap, too short.