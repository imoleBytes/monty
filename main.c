#include "monty.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	stack_t *stack;
	int choice, data;

	stack = NULL;

	while(1)
	{

		// printf("Select Choices\n\n");
		printf("1. push to stack\n2. delete top\n3. list the stack\n4. exit\n");
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
			case 3:
				print_stack(stack);
				break;
			case 4:				
				printf("Exited!\n");
				exit(98);
			default:
				printf("Invalid choice\n");
		}

	}

	return (0);
}
