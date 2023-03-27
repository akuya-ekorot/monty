#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "externs.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to pointer to the top node in stack
 * @line_number: the line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->next->prev = first;

	second->next = first;
	second->prev = NULL;

	first->prev = second;

	*stack = second;
}
