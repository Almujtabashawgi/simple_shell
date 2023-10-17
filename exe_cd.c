#include "main.h"

#define PATH_MAX 1024

/**
 * exec_ce - execute the cd command.
 * @command: The command to be executed.
 * Return: Nothing
 */
void exe_cd(char **command)
{
    char *path = NULL, cwd[PATH_MAX], *home = NULL;

    home = getcwd(cwd, sizeof(cwd));

    if (command[1] == NULL)
    {
        path = getenv("HOME");
        if (path == NULL)
            return;
    }
    else if (_strcmp(command[1], "-") == 0)
    {
        path = getenv("OLDPWD");
        if (path == NULL)
        {
            _putline(home);
            _putchar('\n');
            return;
        }
        _putline(path);
        _putchar('\n');
    }
    else
    {
        path = command[1];
    }

    if (chdir(path) == -1)
    {
        _eputline("./hsh: 1: cd: can't cd to ");
        _eputline(path);
        _eputchar('\n');
        return;
    }

    if (getcwd(cwd, sizeof(cwd)) == NULL)
        return;

    if (setenv("OLDPWD", getenv("PWD"), 1) == -1)
        return;

    if (setenv("PWD", cwd, 1) == -1)
        return;
}