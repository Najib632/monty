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
	/* stack_t_ *stack; */
	ssize_t status = 1;
	size_t lsize = 0;
	unsigned int linenum = 0;

	if (ac != 2)
		argument_error();

	file = fopen(filename, "r");
	if (file == NULL)
		file_error(filename);

	while (status > 0)
	{
		line = NULL;
		status = getline(&line, &lsize, file);
		linenum++;
		if (status > 0)
			printf("%i. %s", linenum, line);
		free(line);
	}

	if (fclose(file) == EOF)
		close_error();

	return (0);
}
