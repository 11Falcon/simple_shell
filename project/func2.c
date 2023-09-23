#include "shell.h"
/**
 * toking - token
 *@input: input
 *@dl: delimiter
 *Return: list
 */
char **toking(char *input, char *dl)
{
	int s = 0;
	char **av = NULL;
	char *token = NULL, *save_ = NULL;

	token = _strtok_r(input, dl, &save_);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * s, sizeof(*av) * (s + 1));
		av[s] = token;
		token = _strtok_r(NULL, dl, &save_);
		s++;
	}

	av = _realloc(av, sizeof(*av) * s, sizeof(*av) * (s + 1));
	av[s] = NULL;

	return (av);
}

/**
 *_write_ - printing
 *@str: string
 *@where: stream
 */
void _write_(char *str, int where)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(where, &str[i], 1);
		i++;
	}
}

/**
 *sup_n_line - removes
 *@str: string to be used
 */
void sup_n_line(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 *_strcpy - copy
 *@src: source
 *@dest: destination
 */
void _scpy(char *src, char *dest)
{
	int i_i = 0;

	for (; src[i_i] != '\0'; i_i++)
		;
		dest[i_i] = src[i_i];
	dest[i_i] = '\0';
}

/**
 *_strlen - counts string length
 *@str: string to be counted
 * Return: length of the string
 */

int _slen(char *str)
{
	int l = 0;

	if (str == NULL)
		return (l);
	while (str[l] != '\0')
		l++;
	return (l);
}
