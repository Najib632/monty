#include "monty.h"

/**
 * pint - prints the value at the top of the stack,
 *        followed by a new line.
 * @stack: Head of the stack
 * @linenum: Number of the line
 * Return: void - nothing
 **/
void pint(stack_t **stack, unsigned int linenum)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
