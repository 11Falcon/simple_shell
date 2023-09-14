#include "shell.h"
#include <stdlib.h>
#include <stddef.h>
int subsplit( char **list, int word)
{
	list = realloc(list, (word + 1) * sizeof(char *));
	error_handling(list, "Error : enter a string\n");
	list[word] = NULL;
	return (0);
}
