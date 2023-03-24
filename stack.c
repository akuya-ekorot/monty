#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include "externs.h"

stack_t *values = NULL;
stack_t *values_tail = NULL;

void print_stack(stack_t *stack)
{
	stack_t *curr;

	curr = stack;

	printf("printing stack\n");
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

void interpret(void)
{
	int i = 0;
	char *token;
	queue_t *node;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	/* retrieve tokens */
	node = deque();
	while (node)
	{
		i = 0;
		token = strtok(node->line, " \n\t\r");
		while (instructions[i].opcode)
		{
			if (strcmp(instructions[i].opcode, token) == 0)
			{
				if (strcmp(token, "pall"))
				{
					token = strtok(NULL, " \n\t\r");
					enqueue_values(atoi(token));
				}
				instructions[i].f(&stack, node->line_number);
			}
			++i;
		}
		node = deque();
	}
}
