#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

/**
 * deque - returns tail node from queue
 * Return: last node
 */
queue_t *deque(void)
{
	queue_t *node;

	if (!queue_tail)
		return (NULL);
	node = queue_tail;
	queue_tail = queue_tail->prev;

	return (node);
}

/**
 * deque_value - returns tail node from value queue
 * Return: last node
 */
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

/**
 * enqueue - adds head node to queue
 * @line: value of new node
 * @line_number: line number of instruction
 */
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

/**
 * enqueue_values - adds head node to values queue
 * @n: value to add to new node
 */
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

/**
 * print_queue - prints queue
 */
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
