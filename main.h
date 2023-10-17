#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>

#define DELIM " \t\n"

char *read_line();
char **pars_input(char *input_line);
extern char **environ;
int exe_command(char **command);
void freeArray(char **arr);
char *_strtok(char *s, const char *delim);
int _getline(char **lineptr, size_t *m, FILE *stream);
char *_getenv(char *envname);
char *getFullPath(char *command);
void update_command(char **command);
void _putchar(char c);
void _eputchar(char c);
void _eputline(char *str);
void _putline(char *str);

char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(char *str1, char *str2, size_t n);

void exe_env();
void exe_setenv(char **command);
void exe_unsetenv(char **command);
void exe_exit(char **command, int *status);
void exe_cd(char **command);

#endif
