#include "shell.h"

/**
 *_strtok_r - tok
 *@str: sentence
 *@dl: delimiter
 *@ash: pointer
 *Return: next tok
 */
char *_strtok_r(char *str, char *dl, char **ash)
{
	char *end;

	if (str == NULL)
		str = *ash;

	if (*str == '\0')
	{
		*ash = str;
		return (NULL);
	}

	str += _strspn(str, dl);
	if (*str == '\0')
	{
		*ash = str;
		return (NULL);
	}

	end = str + _strcspn(str, dl);
	if (*end == '\0')
	{
		*ash = end;
		return (str);
	}

	*end = '\0';
	*ash = end + 1;
	return (str);
}

/**
 * _ati - conv int
 * @s: int
 * Return: int
 */
int _ati(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}

/**
 * _realloc - realloc
 * @ptr: pointer
 * @os: os
 * @ns: size ns
 * Return: new addr memo
 */
void *_realloc(void *ptr, unsigned int os, unsigned int ns)
{
	void *temp;
	unsigned int i;

	if (ptr == NULL)
	{
		temp = malloc(ns);
		return (temp);
	}
	else if (ns == os)
		return (ptr);
	else if (ns == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp = malloc(ns);
		if (temp != NULL)
		{
			for (i = 0; i < min(os, ns); i++)
				*((char *)temp + i) = *((char *)ptr + i);
			free(ptr);
			return (temp);
		}
		else
			return (NULL);

	}
}

/**
 * ctl_c_ - CTRL + C
 * @ash: int
 */
void ctl_c_(int ash)
{
	if (ash == SIGINT)
		_write_("\n($) ", STDIN_FILENO);
}

/**
 * comment - removing comment
 * @ipt: input
 */
void comment(char *ipt)
{
	int i = 0;

	if (ipt[i] == '#')
		ipt[i] = '\0';
	while (ipt[i] != '\0')
	{
		if (ipt[i] == '#' && ipt[i - 1] == ' ')
			break;
		i++;
	}
	ipt[i] = '\0';
}
