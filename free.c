#include "shell.h"
/**
 * free_i_i - free a pointer of pointer
 * @i_i: the pointer of pointer
 */
void free_i_i(char **i_i)
{
	int j;

	for (j = 0; i_i[j] != NULL; j++)
		free(i_i[j]);
	free(i_i);
}
