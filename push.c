#include "monty.h"

/**
 * isdigits - checks if all the characters in a string are digits
 * @digits: string to check
 *
 * Return: 1 (SUCCESS), 0 (FAIL)
 **/
int isdigits(char *digits)
{
	int i;

	for (i = 0; digits[i]; i++)
	{
		if (digits[0] != '+' || !isdigit(digits[i]) || digits[0] != '-')
			return (0);
	}
	return (1);
}

/**
 * push - puts a number into the stack
 * @stack: stack memory to write to
 * @linenum: line number of instruction
 *
 * Return: Nothing
 **/
void push(stack_t **stack, unsigned int linenum)
{
	stack_t *push;

	push = malloc(sizeof(stack_t));
	if (push == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(*stack);
		fclose(core.file);
		exit(EXIT_FAILURE);
	}
	core.operand = strtok(NULL, DELIMS);
	fprintf(stderr, "operand: %s\n", core.operand);
	if (!core.operand)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linenum);
		free_stack(*stack);
		fclose(core.file);
		exit(EXIT_FAILURE);
	}
	push->n = atoi(core.operand);
	push->prev = NULL;
	push->next = *stack;

	if (*stack)
		(*stack)->prev = push;

	*stack = push;
}
