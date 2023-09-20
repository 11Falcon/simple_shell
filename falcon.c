#include "shell.h"

/**
 * split_child1 - reduce lines
 * @string: input
 * @i: index of the current word
 * @list: the list of words
 * Return: a list of words
 */
char **split_child1(const char *string, int i, char **list)
{
	int l, s;

	if (!string || !list)
		return (NULL);
	if (!is_punctuation(*string))
	{
		s = 0;
		l = count_letters(string);
		list[i] = malloc(l + 1);
		if (!list[i])
		{
			error_handling(list, "Error : Memory allocation failed\n");
			return (NULL);
		}
		while (s < l)
		{
			list[i][s] = *string;
			s++;
			string++;
		}
		list[i][l] = '\0';
		i++;
	}
	else
	{
		while (is_punctuation(*string))
			string++;
	}
	return (list);
}

/**
 * split_ - splitting a string to words
 * @string: the sentence to split
 * Return: a list of words
 */
char **split_(const char *string)
{
	char **list = NULL;
	int word = 0, i = 0, j;

	if (!string)
		return (NULL);
	word = number_of_words(string);
	list = malloc((word + 1) * sizeof(char *));
	if (!list)
	{
		error_handling(list, "Error : Memory allocation failed\n");
		return (NULL);
	}
	while (*string)
	{
		list = split_child1(string, i, list);
		if (!list)
		{
			error_handling(list, "Error: split_child1() failed\n");
			for (j = 0; j < i; j++)
				free(list[j]);
			free(list);
			return (NULL);
		}
		while (!is_punctuation(*string))
			string++;
		while (is_punctuation(*string))
			string++;
		i++;
	}
	list[word] = (NULL);
	return (list);
}
