#include "monty.h"

/**
 * get_opcode - matches op codes to respective functions
 * @opcode: operation code to match
 *
 * Return: operation function (SUCCESS), NULL (FAIL)
 **/
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int linenum)
{
	int i;
	instruction_t instruction[] = {
	{"push", push},
	{"pall", pall}, {NULL, NULL}
	};

	for (i = 0; instruction[i].opcode; i++)
	{
		if (!strcmp(instruction[i].opcode, opcode))
		{
			return (instruction[i].f);
		}
	}

	return (NULL);
}
