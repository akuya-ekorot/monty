#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "externs.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the line number of the current instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;
}
