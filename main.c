#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number_nodes = 0;

int main(void)
{
	stack_t *stack;
	int choice, data;
	unsigned int line_no = 0;

	stack = NULL;
	char *file = "tests/some_text.txt";

	FILE *fd = fopen(file, "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	char buff[255];

	// while(1)
	while (fgets(buff, 255, fd) != NULL)
	{
		printf("There are %d nodes now in the stack!\n", number_nodes);

		// printf("Select Choices\n\n");
		// printf("1. push to stack\n2. Print first node\n3. delete top\n4. list the stack\n5. swap\n6. Add first 2 nodes\n7. nop\n8. exit\n");
		// printf("Select Choice: ");
		// scanf("%d", &choice);
		line_no++;

		// if (strcmp(strtok(buff, " "), "push") == 0)

		char *input = strtok(buff, " ");
		
		if (strcmp(input, "push") == 0) {
			// Code for push case
			data = atoi(strtok(NULL, " "));
			push_to_stack(&stack, data);
			// printf("Push operation\n");
		} else if (strcmp(input, "pop") == 0) {
			// Code for pop case
			if (delete_dnodeint_at_index(&stack, 0) == -1)
				{
					printf("L%u: can't pop an empty stack\n", line_no);
					exit(EXIT_FAILURE);
				}
			// printf("Pop operation\n");
		}else if (strcmp(input, "pint") == 0) {
			print_top(stack);
		}else if (strcmp(input, "pall") == 0) {
			print_stack(stack);
			printf("%ld\n", strlen(input));
		}else if (strcmp(input, "swap") == 0) {
			if (number_nodes < 2)
				{
					printf("L%u: can't swap, stack too short\n", line_no);
					exit(EXIT_FAILURE);
				}
				else
					swap_nodes(&stack);
		} else if (strcmp(input, "add") == 0) {
			if (number_nodes < 2)
				{
					printf("L%u: can't add, stack too short\n", line_no);
					exit(EXIT_FAILURE);
				}
				else
				{
					add_func(&stack);
				}
		} else if (strcmp(input, "nop") == 0) {
			;
		}  else {
			// Code for other cases
			printf("Unknown operation (%s) on this line : %u\n", input, line_no);
			printf("%ld\n", strlen(input));
			exit(EXIT_FAILURE);
		}

		/**
		switch (strtok(buff, " "))
		{
			case "push":
				// printf("Enter data to be inserted (int): ");
				// scanf("%d", &data);
				push_to_stack(&stack, strtok(NULL, " "));
				break;
			case "pint":
				print_top(stack);
				break;
			case "pop":
				// printf("delete top of stack\n");
				if (delete_dnodeint_at_index(&stack, 0) == -1)
				{
					printf("L%u: can't pop an empty stack\n", line_no);
					exit(EXIT_FAILURE);
				}
				break;
			case "pall":
				print_stack(stack);
				break;
			case "swap":
				if (number_nodes < 2)
				{
					printf("L%u: can't swap, stack too short\n", line_no);
					exit(EXIT_FAILURE);
				}
				else
					swap_nodes(&stack);
				break;
			case "add":
				if (number_nodes < 2)
				{
					printf("L%u: can't add, stack too short\n", line_no);
					exit(EXIT_FAILURE);
				}
				else
				{
					add_func(&stack);
					break;
				}
			case "nop":
				break;				
			// case 8:				
			// 	printf("Exited!\n");
			// 	exit(98);
			default:
				printf("Invalid choice\n");
		}
		*/
	}

	fclose(fd);

	return (0);
}



// tto swap
// check the len of node, if 2 or morre:
	// delete top
	// insert to index 1
// else, print cannot swap, too short.