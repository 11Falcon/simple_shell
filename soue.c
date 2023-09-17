#include "shell.h"

/**
 * split_child - reduce lines
 * @string: input
 * @i: index of the current word
 * @list: the list of words
 * Return: a list of words
 */
char **split_child(const char *string, int i, char **list)
{
	int l, s, o_o = 0;
	char *path = "/bin/";

	if (!string || !list)
		return (NULL);
	if (*string != '/')
		o_o = 1;
	if (!is_punctuation(*string))
	{
		s = 0;
		l = count_letters(string);
		if (o_o && i == 0)
			l += 5;
		list[i] = malloc(l + 1);
		if (!list[i])
		{
			error_handling(list, "Error : Memory allocation failed\n");
			return (NULL);
		}
		if (o_o && i == 0)
			while (s < 5)
			{
				list[i][s] = *path;
				path++;
				s++;
			}
		while (s < l)
		{
			list[i][s] = *string;
			s++;
			string++;
		}
		list[i][l] = '\0';
		o_o = 0;
		i++;
	}
	else
		while (is_punctuation(*string))
			string++;
	return (list);
}

/**
 * split - splitting a string to words
 * @string: the sentence to split
 * Return: a list of words
 */
char **split(const char *string)
{
	char **list;
	int word, i = 0;

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
		list = split_child(string, i, list);
		if (!list)
			return (NULL);
		if (!list[i])
		{
			error_handling(list, "Error : split_child() failed\n");
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
