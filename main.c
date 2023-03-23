#include <stdio.h>
#include <stdlib.h>
#include "externs.h"
#include "monty.h"

queue_t *queue = NULL;
queue_t *queue_tail = NULL;

int main(void)
{
	drive_enqueue();
	printf("%s", deque());
	printf("%s", deque());
	printf("%s", deque());
	printf("%s", deque());
	return (EXIT_SUCCESS);
}
