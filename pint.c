#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pint - print value at the top of the stack
 * @stack: stack
 * @line_number: line number of instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
