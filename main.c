#include "main.h"
int main(int ac, char **argv)
{
	char *lineptr = NULL, **command = NULL;
	int status = 0;
	(void)ac; (void)argv;

	while (1){
		lineptr = read_line();
		if (!isatty(STDIN_FILENO))
		{
			write(STDIN_FILENO,"\n",1);
		}
		if (_strcmp(lineptr, "exit\n") == 0)
        {
				free(lineptr);
				exit(0);
		}
        command = pars_input(lineptr);
        if (!command)
			continue;
		
		if (_strcmp(command[0], "exit") == 0)
		{
			exe_exit(command, &status);
		}
		else if (_strcmp(command[0], "env") == 0)
		{
			freeArray(command);
			exe_env();
			status = 0;
			continue;
		}
		else if (_strcmp(command[0], "setenv") == 0)
		{
			exe_setenv(command);
			status = 0;
			freeArray(command);
			continue;
		}
		else if (_strcmp(command[0], "unsetenv") == 0)
		{
			exe_unsetenv(command);
			status = 0;
			freeArray(command);
			continue;
		}
		else if (_strcmp(command[0], "cd") == 0)
		{
			exe_cd(command);
			status = 0;
			freeArray(command);
			continue;
		}
		update_command(command);
		status = exe_command(command);
	}
}
