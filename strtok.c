#include "main.h"

char *_strchr(const char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == (char)c)
        {
            return (char *)str;
        }
        str++;
    }

    if (*str == (char)c)
    {
        return (char *)str;
    }

    return NULL;
}

size_t _strspn(const char *str, const char *accept)
{
    size_t count = 0;

    while (*str != '\0' && _strchr(accept, *str) != NULL)
    {
        count++;
        str++;
    }

    return (count);
}

char *_strpbrk(const char *str, const char *accept)
{
    while (*str != '\0')
    {
        if (_strchr(accept, *str) != NULL)
        {
            return (char *)str;
        }
        str++;
    }

    return (NULL);
}

char *_strtok(char *s, const char *delim)
{
    static char *last_token = NULL;
    char *star_token;

    if (s == NULL)
    {
        s = last_token;
    }

    s += _strspn(s, delim);

    if (*s == '\0')
    {
        last_token = NULL;
        return NULL;
    }

    star_token = s;

    s = _strpbrk(star_token, delim);
    if (s != NULL)
    {
        *s = '\0';
        last_token = s + 1;
    }
    else
    {
        last_token = _strchr(star_token, '\0');
    }

    return star_token;
}
