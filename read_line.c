#include "main.h"

/**
 * read_line - Read line of input from stdin
 * Return: A pointer to the input line, or NULL if there was no input.
 */
char *read_line()
{
  char *buffer = NULL;
  size_t buffer_size = 0;
  int read;

  if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "$ ", 2);

  read = _getline(&buffer, &buffer_size, stdin);

  if (read == -1)
  {
    free(buffer);
    write (STDIN_FILENO, "\n", 1);
    exit (0);
    
  }

  return (buffer);
}
