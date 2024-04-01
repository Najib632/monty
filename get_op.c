#include "monty.h"

/**
 * available - checks if opcode is available in instructions
 * @iopcode: instruction opcode
 * @opcode: opcode to verify
 *
 * Return: 1 (SUCCESS), 0 (FAIL)
 **/
int available(char *iopcode, char *opcode)
{
	int i;

	if (opcode == NULL)
		return (0);
	for (i = 0; opcode[i]; i++)
	{
		if (opcode[i] != iopcode[i])
			return (0);
	}
	return (1);
}

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
	{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}
	};

	for (i = 0; instruction[i].opcode; i++)
	{
		if (available(instruction[i].opcode, opcode))
			return (instruction[i].f);
	}
	return (NULL);
}
