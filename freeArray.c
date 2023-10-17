#include "main.h"

/**
 * free_array - free allocated space of an array.
 * @arr: the array to free
 */
void freeArray(char **arr)
{
	int i;

	if (!arr)
	return;

	for (i = 0; arr[i]; i++)
	{
	free(arr[i]);
	arr[i] = NULL;
	}

	free(arr), arr = NULL;
}