#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"
/**
 * split - spliting the user input into words
 * @string: user input
 * Return: argv[arg]
 */
char **split(const char *string)
{
	char **list = NULL;
	int word = 0, first = 1, i = 0;
	const char *start = string;

	if (!string)
		return (list);
	while (*string)
	{
		if (*string != ' ' && *string != '\t')
		{
			if (*string != '\n' && *string != '\r' && *string != '\a')
			{	
				if (first)
				{
					list = realloc(list, (word + 1) * sizeof(char *));
					error_handling(list, "Error : enter a string\n");
					list[word] = NULL;
					first = 0;
				}
				list[word] = realloc(list[word], (i + 2) * sizeof(char *));
				error_handling(list[word], "Error : enter a string\n");
				list[word][i] = *string;
				i++;
				string++;
			}
		}
		else
		{
			while (*string == ' ' || *string == '\t' || *string == '\n' || *string == '\r' || *string == '\a')
				string++;
			if (!first)
			{
				list[word][i] = '\0';
				word++;
				i = 0;
				first = 1;
			}
		}
	}
	if (!first)
	{
		list[word][i] = '\0';
		word++;
	}
	list = realloc(list, (word + 1) * sizeof(char *));
	error_handling(list, "Error : Memory allocation failed\n");
	list[word] = NULL;
	return (list);
}
