#include "shell.h"
/**
 * split - splitting a string to words
 * @string: the sentence to split
 * Return: a list of words
 */
char **split(const char *string)
{
	char **list;
	int s, l, word, i = 0;

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
			while (is_punctuation(*string))
				string++;
	}
	list[word] = (NULL);
	return (list);
}
