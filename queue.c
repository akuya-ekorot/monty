#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

queue_t *deque(void)
{
	queue_t *node;
	if (!queue_tail)
		return (NULL);
	node = queue_tail;
	queue_tail = queue_tail->prev;
	return (node);
}

stack_t *deque_value(void)
{
	stack_t *node;
	if (!values_tail)
		return (NULL);
	node = values_tail;
	values_tail = values_tail->prev;
	node->prev = NULL;
	return (node);
}

void enqueue(char *line, int line_number)
{
	queue_t *new;
	new =  malloc(sizeof(queue_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->line = line;
	new->line_number = line_number;
	new->next = queue;
	if (new->next)
		new->next->prev = new;
	queue = new;
	if (!queue_tail)
		queue_tail = queue;
}

void enqueue_values(int n)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = values;
	if (new->next)
		new->next->prev = new;
	values = new;
	if (!values_tail)
		values_tail = values;
}

void print_queue(void)
{
	queue_t *tmp;
	tmp = queue;
	while (tmp)
	{
		printf("L%d: %s", tmp->line_number, tmp->line);
		tmp = tmp->next;
	}
}
