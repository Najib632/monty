#ifndef _MONTY_H_
#define _MONTY_H_

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define DELIMS "\t\n "

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

/**
 * struct core_s - core memory and token details
 * @instrcnt: number of instructions
 * @stack: stack memory
 * @opcode: operation code
 * @operand: value to load
 *
 * Description: stack memory and instruction details
 */
typedef struct core_s
{
	int instrcnt;
	stack_t **stack;
	char *opcode;
	char *operand;
} core_t;
extern core_t core;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);
void operation(stack_t **, char *, unsigned int);
void free_stack(stack_t *stack);

#endif /* _MONTY_H_ */
