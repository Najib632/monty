#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Head of the list
 * @linenum: Number of the line
 * Return: void - nothing
 **/
void pop(stack_t **stack, unsigned int linenum)
{
	stack_t *new_list = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenum);
		free_stack(*stack);
		fclose(core.file);
		exit(EXIT_FAILURE);
	}
	new_list = (*stack)->next;
	free(*stack);
	*stack = new_list;
}
