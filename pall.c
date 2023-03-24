#include <stdio.h>
#include "monty.h"
#include "externs.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;
	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
