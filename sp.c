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
                        error_handling(list[word], "Error : enter a string\n");
			s = 0;
			l = count_letters(string);
			list[i] = malloc (l);
			while (s < l)
			{
				list[word][s] = *string;
				s++;
				string++;
			}
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
