#include <stdlib.h>
#include <stdio.h>

/**
 * program_usage - checks if user passed in a file as a command line arguement
 * @ac: number of command line arguements
 */
static void program_usage(int ac)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point of the program. A monty interpreter
 * @ac: count of command line arguements
 * @av: list of command line arguements
 *
 * Return: Always EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	program_usage(ac);
	return (EXIT_SUCCESS);
}

