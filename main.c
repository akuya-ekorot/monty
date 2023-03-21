#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

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
 * open_file - opens file passed in as a command line arguement
 * @path: file to path. part of av
 *
 * Return: file stream
 */
static FILE *open_file(char *path)
{
	FILE *file;

	file = fopen(path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}

	return (file);
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
	FILE *file;

	program_usage(ac);
	file = open_file(av[1]);
	read_line(file);

	fclose(file);

	return (EXIT_SUCCESS);
}

