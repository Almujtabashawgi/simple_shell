#include "main.h"

#define BUFFER_SIZE 1024

int _fgetc(FILE *stream)
{
    unsigned char ch;
    ssize_t bytes_read = read(fileno(stream), &ch, 1);

    if (bytes_read == 1)
        return ch;
    else
        return EOF;
}

/**
 * _getline - read a line from stdin
 */
int _getline(char **buffer_ptr, size_t *buffer_size, FILE *stream)
{
    size_t line = 0;
    int buffer_index;

    if (buffer_ptr == NULL || buffer_size == NULL || stream == NULL)
        return (-1);

    if (*buffer_ptr == NULL)
    {
        *buffer_size = BUFFER_SIZE;
        *buffer_ptr = malloc(*buffer_size);

        if (*buffer_ptr == NULL)
        {
            return (-1);
        }
    }

    while ((buffer_index = _fgetc(stream)) != EOF)
    {
        if (buffer_index == '\n')
            break;

        (*buffer_ptr)[line++] = buffer_index;
        if (line == *buffer_size)
        {
            *buffer_size *= 2;
            *buffer_ptr = realloc(*buffer_ptr, *buffer_size);
            if (*buffer_ptr == NULL)
                return (-1);
        }
    }
    if (buffer_index == EOF)
        return (-1);

    (*buffer_ptr)[line] = '\0';
    return (line);
}