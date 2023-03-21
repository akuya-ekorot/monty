#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * get_tokens - gets token from a line
 * @line: line to interpret
 * @line_number: line number
 */
void get_tokens(char *line, int line_number)
{
	char *token;
  int token_number;

  token = strtok(line, " \n");
	token_number = 0;

	while (token)
	{
		printf("Line %d, Token %d: %s\n", line_number, ++token_number, token);
		token = strtok(NULL, " \n");
	}
}

/**
 * read_line - reads line from file stream
 * @file: file stream
 */
void read_line(FILE *file)
{
  char *line = NULL;
  size_t bufsize = 0;
  ssize_t nread;
  int line_number = 0;

  while ((nread = getline(&line, &bufsize, file)) != -1)
		get_tokens(line, ++line_number);

}
