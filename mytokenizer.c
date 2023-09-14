#include "shell.h"

/**
* strtow - cut a gien string into words
* @str: the string to cut
* @del: the delimiters usedel to cut the string
* Return: an array that contains the words of the string, NULL otherwise
*/
char **strtow(char *str, char *del)
{
	int idx = 0, start = 0, l = 0, words = 0;
	int i, j, k;
	int len = _strlen(str);
	char **array;

	if (!str || !str[0])
		return (NULL);
	if (!del)
		del = " ";
	for (i = 0; str[i]; i++)
		if (!is_delim(str[i], del) && (is_delim(str[i + 1], del) || !str[i + 1]))
			words++;
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		if (str[i] == '\0' || is_delim(str[i], del))
		{
			array[idx] = malloc((l + 1) * sizeof(char));
			if (!array[idx])
			{
				for (j = 0; j < idx; j++)
					free(array[j]);
				free(array);
				return (NULL);
			}
			for (k = 0; k < l; k++)
				array[idx][k] = str[start + k];
			array[idx][l] = '\0';
			idx++;
			l = 0;
			start = i + 1;
		}
		else
			l++;
	}
	array[words] = NULL;
	return (array);
}

/**
* strtow2 - cut a given string into words
* @str: the string to splite
* @del: the delimiters usedel to cut the string
* Return: an array that contains the words of the string, NULL otherwise
*/
char **strtow2(char *str, char del)
{
	int idx = 0, start = 0, l = 0, words = 0;
	int i, j, k;
	int len = _strlen(str);
	char **array;

	if (!str || !str[0])
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i] != del && str[i + 1] == del)
			words++;
		else if (str[i + 1] == del || (str[i] != del && str[i + 1] == '\0'))
			words++
	}
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		if (str[i] == '\0' || str[i] == del)
		{
			array[idx] = malloc((l + 1) * sizeof(char));
			if (!array[idx])
			{
				for (j = 0; j < idx; j++)
					free(array[j]);
				free(array);
				return (NULL);
			}
			for (k = 0; k < l; k++)
				array[idx][k] = str[start + k];
			array[idx][l] = '\0';
			idx++;
			l = 0;
			start = i + 1;
		}
		else
			l++;
	}
	array[words] = NULL;
	return (array);
}
