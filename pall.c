#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: stack memory to print from
 * @line_number: line number of instruction in the file
 *
 * Return: Nothing.
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pall = *stack;
	(void) line_number;

	while (pall)
	{
		fprintf(stdout, "%d\n", pall->n);
		pall = pall->next;
	}
}
