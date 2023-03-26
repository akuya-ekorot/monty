#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

queue_t *queue = NULL;
queue_t *queue_tail = NULL;
stack_t *values = NULL;
stack_t *values_tail = NULL;

/**
 * main - monty bytecode interpreter
 * @ac: number of command line arguements
 * @av: list of command line arguements
 *
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t n = 0;
	int line_number = 0;
	ssize_t nread;

	/* usage */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file and add lines to queue */
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &n, file)) != -1)
	{
		enqueue(line, ++line_number);
		line = NULL;
		n = 0;
	}

	interpret();
	fclose(file);

	free(line);
	free_queue();
	free_values();

	return (EXIT_SUCCESS);
}
