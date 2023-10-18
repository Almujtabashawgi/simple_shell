#include "main.h"

/**
 * _strcat - concatenates between two string
 * @dest: destniation string
 * @src: source string
 * Return: pointer of dest
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}
/**
 * _strlen - compute the length of a string.
 * @str: the input string
 * Return: the length
 */

int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}

/**
 * _strcpy - copy source string to dest
 * @dest: destination string
 * @src: source string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return dest;
}

/**
 * _strdup - duplicate string.
 * @str: the string
 * Return: a duplicate of input string
 */

char *_strdup(char *str)
{
	size_t len = strlen(str) + 1;
	char *new_str = (char *)malloc(len * sizeof(char));

	if (new_str == NULL)
		exit(EXIT_FAILURE);

	strcpy(new_str, str);
	return (new_str);
}
/**
 * _strcmp - copmare between two string
 * @string1: first string
 * @string2: seconed string
 * Return: 0 or negitvie or positive
 */

int _strcmp(char *string1, char *string2)
{
	while (*string1 != '\0' && *string1 == *string2)
	{
		string1++;
		string2++;
	}

	return (*string1 - *string2);
}
/**
 * _strncmp - compare between two strings.
 * @string1: string 1
 * @string2: string 2
 * @n: maximum size
 * Return: flag
 */
int _strncmp(char *string1, char *string2, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (string1[i] != string2[i])
		{
			return string1[i] - string2[i];
		}
		if (string1[i] == '\0')
		{
			break;
		}
	}
	return 0;
}
