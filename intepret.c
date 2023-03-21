#include <stdio.h>
#include "monty.h"

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
    printf("line %d: %s", ++line_number, line);

}
