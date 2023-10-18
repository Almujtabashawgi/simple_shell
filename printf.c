#include "main.h"

/**
 * _putchar - writes the character c to the std output
 * @c: The character to be printed
 */
void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to be printed
 */
void _eputchar(char c)
{
	write(STDERR_FILENO, &c, 1);
}

/**
 * _eputline - writes the string str to the std output
 * @str: the string
 */
void _eputline(char *str)
{
	while (*str != '\0')
	{
		_eputchar(*str);
		str++;
	}
}

/**
 * _putline - writes the string str to the std output
 * @str: the string
 */
void _putline(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
