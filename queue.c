#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

char *deque(void)
{
	char *line;

	line = queue_tail->line;
	queue_tail = queue_tail->prev;

	return (line);
}

void enqueue(char *line)
{
	queue_t *new;
	
	if (!queue)
	{
		queue = malloc(sizeof(queue_t));
		if (!queue)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		queue->line = line;
		queue->next = NULL;
		queue->prev = NULL;
		queue_tail = queue;
	}
	else
	{
		new = malloc(sizeof(queue_t));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		new->line = line;
		new->next = queue;
		new->next->prev = new;
		queue = new;
	}
}

void drive_enqueue(void)
{
	enqueue("Hello\n");
	enqueue("there\n");
	enqueue("Akuya\n");
	enqueue("Ekorot\n");
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
