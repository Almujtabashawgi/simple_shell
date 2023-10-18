#include "main.h"

/**
 * update_command_zero - get the full path of the command.
 * @command: the command to find the path to
 */
void update_command(char **command)
{
	size_t length_new_value;
	char *new_value = getFullPath(command[0]);

	if (new_value == NULL)
		return;

	free(command[0]);
	length_new_value = _strlen(new_value);
	command[0] = malloc((length_new_value + 1) * sizeof(char));

	_strcpy(command[0], new_value);

	free(new_value);
}
