#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

queue_t *queue = NULL;
queue_t *queue_tail = NULL;

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t n = 0;
	ssize_t nread;

	/* usage */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* file */
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: couldn't open file");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &n, file)) != -1)
	{
		enqueue(line);
		line = NULL;
		n = 0;
	}

	fclose(file);
	if (line)
		free(line);

	print_queue();

	return (EXIT_SUCCESS);
}
