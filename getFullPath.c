
#include "main.h"
#define MAX_PATH_LENGTH 1024
#define PATH_SEPARATOR ":"
/**
 * get_full_path - path of simple shell
 * @command: execute
 * Return: 0
 */

char *getFullPath(char *command)
{
    char *full_path = NULL;
    char *path_env = _getenv("PATH");
    char *path_copy;
    char *token;
    char buffer[MAX_PATH_LENGTH];

    if (strchr(command, '/') != NULL)
    {
        /* The command already contains a slash, so it is assumed to be a full path */
        full_path = _strdup(command);
        return full_path;
    }
    if (path_env == NULL)
    {
        return NULL;
    }
    /* Tokenize the PATH environment variable */
    path_copy = _strdup(path_env);
    token = _strtok(path_copy, PATH_SEPARATOR);
    while (token != NULL)
    {
        /* Compose the full path by concatenating the command and each directory in PATH */
        _strcpy(buffer, token);
        _strcat(buffer, "/");
        _strcat(buffer, command);
        if (access(buffer, X_OK) == 0)
        {
            /* The command exists in the current directory, so we found the full path */
            full_path = _strdup(buffer);
            break;
        }
        token = _strtok(NULL, PATH_SEPARATOR);
    }
    free(path_copy);
    return full_path;
}