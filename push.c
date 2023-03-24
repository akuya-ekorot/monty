#include <stdio.h>
#include "monty.h"
#include "externs.h"

/**
 * push - implement push instruction. add values to stack
 * @stack: pointer to linked list representation of stack.
 * points to top node on stack
 * @line_number: line number of instruction
 */
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
