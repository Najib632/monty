#include "monty.h"

/**
 * operation - it carries the operation specified by the instruction
 * @stack: stack memory
 * @opcode: operation code
 * @linenum: line number
 *
 * Return: 1 (SUCCESS), 0 (FAIL)
 **/
void operation(stack_t **stack, char *opcode, unsigned int linenum)
{
	void (*execute)(stack_t **stack, unsigned int line_number);

	execute = get_opcode(opcode);
	if (opcode && execute == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	execute(stack, linenum);
}
