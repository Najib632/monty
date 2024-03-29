#include "monty.h"

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
	ssize_t status;
	size_t linsize = 0, linenum = 0;

	if (ac != 2)
		argument_error();

	file = fopen(filename, "r");
	if (file == NULL)
		file_error(filename);

	while (status > 0)
	{
		line = NULL;
		status = getline(&line, &linlen, file);
		linenum++;
		free(line);
	}

	if (fclose(file) == EOF)
		close_error();

	return (0);
}
