#include "shell.h"
/**
 * custom
char **custom_strtok(char *str) {
	char *next_token = NULL;
	char **ptr = NULL;
	char *delim = " \t\n";
	int i = 0;

	if (!str)
		return (NULL);
	ptr = malloc(sizeof(char *) * 800);
	if (!ptr)
		return (NULL);
	next_token = strtok(str, delim);
	if (next_token == NULL)
	{
		free(str);
		free(ptr);
		return (NULL);
	}
	while (next_token)
	{
		ptr[i] = strdup(next_token);
		next_token = strtok(NULL, delim);
		i++;
	}
	free(str);
	ptr[i] = NULL;
	return (ptr);
}
