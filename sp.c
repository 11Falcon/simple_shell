#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"
char **split(const char *string)
{
	char **list = NULL;
	int word, first = 1, i = 0;
	const char *start = string;
	if (!string)
		return (list);
	word = number_of_words(string);
	list = malloc(word * sizeof(char*));
	while (*string)
	{
		if (!is_punctuation(*string))
		{
			if (first)
			{
				error_handling(list, "Error : enter a string\n");
				list[i] = NULL;
				first = 0;
			}
			list[i] = re
				alloc(list[word], (i + 2) * sizeof(char*));
			error_handling(list[word], "Error : enter a string\n");
			list[word][i] = *string;
			i++;
			string++;
		}
		else
		{
			while (is_punctuation(*string))
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
	list = realloc(list, (word + 1) * sizeof(char*));
	error_handling(list, "Error : Memory allocation failed\n");
	list[word] = NULL;
	return (list);
}
