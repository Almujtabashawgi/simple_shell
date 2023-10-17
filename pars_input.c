#include "main.h"

/*
 * pars_input - Parses a command line into an array of arguments.
 *
 * The command line is expected to be a string of space-separated arguments.
 *
 * Returns a pointer to an array of arguments, or NULL if an error occurred.
 */
char **pars_input(char *input_line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int tokens_count = 0, i = 0;

	if (!input_line)
		return (NULL);

	tmp = _strdup(input_line);
	token = _strtok(tmp, DELIM);

	if (token == NULL)
	{
		free(input_line), input_line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		tokens_count++;
		token = _strtok(NULL, DELIM);
	}

	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (tokens_count + 1));
	if (!command)
	{
		free(input_line);
		return (NULL);
	}
	token = _strtok(input_line, DELIM);

	while (token)
	{
		command[i] = _strdup(token);
		token = _strtok(NULL, DELIM);
		i++;
	}
	free(input_line), input_line = NULL;
	command[i] = NULL;
	return (command);
}
