#include <stdio.h>
#include "monty.h"
#include "externs.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = deque_value();
	new->next = *stack;

	if (new->next)
		new->next->prev = new;

	*stack = new;
}
