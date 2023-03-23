#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

char *deque(void)
{
	char *line;

	if (!queue_tail)
		return (NULL);

	line = queue_tail->line;
	queue_tail = queue_tail->prev;

	return (line);
}

void enqueue(char *line)
{
	queue_t *new;
	
	new = (queue_t *) malloc(sizeof(queue_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->line = line;
	new->next = queue;
	queue = new;
}

void print_queue(void)
{
	queue_t *tmp;

	tmp = queue;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}
