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
	/* stack_t *stack; */
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
	{
		perror("close");
		exit(EXIT_FAILURE);
	}

	return (0);
}
