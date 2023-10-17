#include "main.h"

/**
 * _getenv - get environment path of enviroment variable
 * @name: the name of the enviroment variable
 * Return: The path of enviroment variable
 */
char *_getenv(char *envname)
{
	size_t len = _strlen(envname);
	char **envi;

	for (envi = environ; *envi != NULL; envi++)
	{
		if (_strncmp(*envi, envname, len) == 0 && (*envi)[len] == '=')
		{
			return (&(*envi)[len + 1]);
		}
	}

	return (NULL);
}