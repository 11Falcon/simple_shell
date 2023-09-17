#include "shell.h"
/**
 * split_child - reduce lines
 * @string: input
 */
char **split_child(const char *string, int i, char **list)
{
	int l, s;

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
	return (list);
}
