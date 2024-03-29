#include "monty.h"

/**
 * get_opcode - matches op codes to respective functions
 * @opcode: operation code to match
 *
 * Return: operation function (SUCCESS), NULL (FAIL)
 **/
void (*get_opcode(char *opcode))(stack_t_ **stack, unsigned int linenum)
{
	instruction_t instruction[] = {
	{"push", NULL}, {NULL, NULL}
	};
	int i;

	for (i = 0; instruction[i].opcode; i++)
	{
		if (!strcmp(instruction[i].opcode, opcode))
		{
			return (instruction[i].f);
		}
	}

	return (NULL);
}
