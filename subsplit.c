#include "shell.h"
#include <stdlib.h>
#include <stddef.h>
void subsplit( char **list, int word, int first)
{
	list = realloc(list, (word + 1) * sizeof(char *));
	error_handling(list, "Error : enter a string\n");
	list[word] = NULL;
	first = 0;
}
