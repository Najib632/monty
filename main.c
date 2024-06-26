#include "monty.h"

core_t core;

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0 (SUCCESS)
 **/
int main(int ac, char *av[])
{
	FILE *file;
	char *filename = av[1], *line;
	stack_t *stack;
	ssize_t status = 1;
	size_t lsize = 0;
	unsigned int linenum = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	core.file = file;
	core.stack = &stack;
	while ((status = getline(&line, &lsize, file)) != EOF)
	{
		linenum++;
		core.opcode = strtok(line, DELIMS);
		execute(core.stack, core.opcode, linenum);
		free(line);
	}
	free_stack(*core.stack);
	fclose(file);
	return (0);
}
