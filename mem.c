#include <stdlib.h>
#include "monty.h"
#include "externs.h"

/**
 * free_queue - frees queue's mem
 */
void free_queue(void)
{
	queue_t *curr;

	while (queue)
	{
		curr = queue;
		queue = queue->next;
		free(curr->line);
		free(curr);
	}
}

/**
 * free_values - frees queue's mem
 */
void free_values(void)
{
	stack_t *curr;

	while (values)
	{
		curr = values;
		values = values->next;
		free(curr);
	}
}

