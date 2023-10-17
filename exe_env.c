#include "main.h"

/**
 * exec_env - execute env command
 */
void exe_env()
{
    char **envi = environ;

    while (*envi)
    {
        _putline(*envi);
        _putchar('\n');
        envi++;
    }
}

/**
 * _setenv - set environment variable
 * @command: the command
 */
void exe_setenv(char **command)
{
    if (command[1] == NULL || command[2] == NULL)
        return;

    if (setenv(command[1], command[2], 1) != 0)
    {
        _eputline("Error setting environment variable\n");
    }
}

/**
 * _unsetenv - unset environment variable
 * @command: the command
 */
void exe_unsetenv(char **command)
{
    if (command[1] == NULL)
        return;

    if (unsetenv(command[1]) != 0)
    {
        _eputline("Error unsetting environment variable\n");
    }
}