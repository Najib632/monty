#include "monty.h"

/**
 * execute - it carries the execute specified by the instruction
 * @stack: stack memory
 * @opcode: execute code
 * @linenum: line number
 *
 * Return: 1 (SUCCESS), 0 (FAIL)
 **/
void execute(stack_t **stack, char *opcode, unsigned int linenum)
{
	void (*operation)(stack_t **stack, unsigned int line_number);

	operation = get_opcode(opcode);
	if (operation == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	operation(stack, linenum);
}
