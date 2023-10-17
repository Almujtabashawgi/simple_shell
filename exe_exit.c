#include "main.h"

/**
 * is_not_numerical - check if a string cannot be casted to integer or not
 * @str: the string
 * Return: 1 if success, 0 if fail
 */
int isnotnumerical(char *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;

    if (str[0] == '-')
        i = 1;

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 1;
        }
        i++;
    }

    return 0;
}

/**
 * exe_exit - exit from the shell
 * @command: the command
 * @status: the status
 */
void exe_exit(char **command, int *status)
{
    if (command[1] == NULL)
    {
        freeArray(command);
        exit(*status);
    }

    *status = atoi(command[1]);

    if (command[1][0] == '-')
    {
        *status = 2;
        _eputline("./hsh: 1: exit: Illegal number: ");
        _eputline(command[1]);
        _eputline("\n");
        freeArray(command);
        exit(*status);
    }
    else if (isnotnumerical(command[1]))
    {
        *status = 2;
        _eputline("./hsh: 1: exit: Illegal number: ");
        _eputline(command[1]);
        _eputline("\n");
        freeArray(command);
        exit(*status);
    }

    freeArray(command);
    exit(*status);
}