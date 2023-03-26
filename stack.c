#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
 * check_instruction - checks for opcode and instruction
 * @opcode: the opcode
 * @token: the token
 * @node: queue of file lines to work on
 *
 * Return: 1 or 0
 */
static int check_instruction(char *opcode, char *token, queue_t **node)
{
	long num;
	char *endptr;

	errno = 0;
	if (strcmp(opcode, token) == 0)
	{
		if (!(strcmp(token, "pall") == 0 || strcmp(token, "pint") == 0))
		{
			token = strtok(NULL, " \n\t\r");
			if (!token)
				push_error(*node);

			num = strtol(token, &endptr, 10);
			if (errno || *endptr)
				push_error(*node);

			enqueue_values((int)num);
		}
		return (1);
	}
	return (0);
}

/**
 * interpret - inteprets the lines in queue
 */
void interpret(void)
{
	int i, found;
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

		if (!token)
			continue;

		while (instructions[i].opcode)
		{
			found = check_instruction(instructions[i].opcode, token, &node);

			if (found)
			{
				instructions[i].f(&stack, node->line_number);
				break;
			}
			++i;
		}

		if (!found)
			unknown_instruction(node, token);
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
	exit(EXIT_FAILURE);
}

