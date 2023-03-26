#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#include "externs.h"

/**
 * print_stack - prints the values in stack
 * @stack: head node of stack
 */
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

/**
 * interpret - inteprets the lines in queue
 */
void interpret(void)
{
	int i = 0, found;
	char *token;
	queue_t *node;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL},
	};

	while ((node = deque()))
	{
		i = 0, found = 0;
		token = strtok(node->line, " \n\t\r");
		if (token)
		{
			while (instructions[i].opcode)
			{
				if (strcmp(instructions[i].opcode, token) == 0)
				{
					found = 1;
					if (strcmp(token, "pall") && strcmp(token, "pint"))
					{
						token = strtok(NULL, " \n\t\r");
						if (!token || !atoi(token))
							push_error(node);
						enqueue_values(atoi(token));
					}
					instructions[i].f(&stack, node->line_number);
				}
				++i;
			}
			if (!found)
				unknown_instruction(node, token);
		}
		else
			continue;
	}
}

/**
 * unknown_instruction - handle unknown instruction error
 * @node: node with line number
 * @token: the unknown instruction
 */
void unknown_instruction(queue_t *node, char *token)
{
	fprintf(stderr, "L%d: unkown instruction %s\n", node->line_number, token);
	exit(EXIT_SUCCESS);
}

