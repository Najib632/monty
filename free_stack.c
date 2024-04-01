#include "monty.h"

/**
 * free_stack - free the stack memory
 * @stack: stack memory head
 *
 * Return: Nothing
 **/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
