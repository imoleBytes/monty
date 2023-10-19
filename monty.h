#ifndef _monty_h
#define _monty_h



extern int number_nodes;
extern unsigned int line_no;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/** helper functions  */
stack_t *push_to_stack(stack_t **head, const int n);
void print_stack(const stack_t *h);
void print_str(const stack_t *h);
void print_top(const stack_t *h);
void print_top_char(const stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *insert_to_idx_1(stack_t **h, unsigned int idx, int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void swap_nodes(stack_t **h);
void add_func(stack_t **h);
void sub_func(stack_t **h);
void div_func(stack_t **h);
void mul_func(stack_t **h);
void mod_func(stack_t **h);

#endif
