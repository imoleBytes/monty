#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	char **args;
	unsigned int line_no = 0;

	FILE *fd = fopen("some_text.txt", "r");

	if (fd != NULL)
	{
		char buff[1024];

		while (fgets(buff, 1024, fd) != NULL)
		{
			line_no++;

			args[0] = strtok(buff, " ");
			args[1] = strtok(NULL, " ");

			// printf("line %u: args[0] is %s\n", line_no, args[0]);
			// printf("line %u: args[1] is %s\n", line_no, args[1]);

			// printf("line %u: %s\n", line_no, buff);
			// printf("line %u: %s\n", line_no, buff);
			
			switch (*args[0])
			{
				case "push":
					printf("Line %u: push this [%s] into the stack\n", line_no, args[1]);
					break;
				case "pint":
					printf("Line %u: print the top of stack", line_no);
					break;
				case "pop":
					printf("Line %u: delete top of stack\n", line_no);
					break;
				case "pall":
					printf("Line %u: print all of the stack", line_no);
					break;
				case "swap":
					printf("Line %u: swap the top 2 of stack", line_no);
					break;
				case "add":
					printf("Line %u: add the top of stack", line_no);
					break;
				case "nop":
					printf("Line %u: nothing happens here", line_no);
					break;				
				case "exit":		
					printf("Exited!\n");
					exit(98);
				default:
					printf("Invalid choice\n");
			}
		
			// printf("%s\n",strtok(buff, " "));
			// printf("%s\n",strtok(NULL, " "));
		}
				
	}
	fclose(fd);
	return (0);
}