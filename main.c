#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number_nodes = 0;
unsigned int line_no = 0;

int main(int ac, char **av)
{
	stack_t *stack;
	int data;
	char *file;
	FILE *fd;
	char buff[255];
	char *input;
	char *sec_item;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	stack = NULL;
	file = "tests/some_text.txt";
	file = av[1];

	fd = fopen(file, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	


	while (fgets(buff, 255, fd) != NULL)
	{
		line_no++;

		if (buff[0] == '\n' || buff[0] == '\0')
			continue;
		
		input = strtok(buff, " \t\r\n");
		
		if (strcmp(input, "push") == 0) {
			sec_item = strtok(NULL, " \t\r\n");
			if (sec_item)
			{
				data = atoi(sec_item);
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_no);
				exit(EXIT_FAILURE);
			}

			push_to_stack(&stack, data);
			
		} else if (strcmp(input, "pop") == 0) {
			if (delete_dnodeint_at_index(&stack, 0) == -1)
				{
					fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
					exit(EXIT_FAILURE);
				}
		}else if (strcmp(input, "pint") == 0) {
			print_top(stack);
		}else if (strcmp(input, "pall") == 0) {
			print_stack(stack);
		}else if (strcmp(input, "swap") == 0) {
			if (number_nodes < 2)
				{
					fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
					exit(EXIT_FAILURE);
				}
				else
					swap_nodes(&stack);
		} else if (strcmp(input, "add") == 0) {
			if (number_nodes < 2)
				{
					fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
					exit(EXIT_FAILURE);
				}
				else
				{
					add_func(&stack);
				}
		} else if (strcmp(input, "nop") == 0) {
			;
		}  else {
			/** Code for other cases */
			fprintf(stderr,"L%u: unknown instruction %s\n", line_no, input);
			exit(EXIT_FAILURE);
		}

	
	}

	fclose(fd);

	return (0);
}

