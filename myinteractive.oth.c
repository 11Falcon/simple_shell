#include "shell.h"

/**
* interactive - check if we are in the interactive mode
* @info: struct that contains arguments
* Return: 1 if interactive mode, 0 if no
*/
int interactive(info_t *info)
{
	int i = isatty(STDIN_FILENO);
	int j = (info->readfd <= 2);

	if (i && j)
		return (1);
	else
		return (0);
}

/**
* is_delim - check if any delimiters exist
* @ch: the character to check
* @del: the delimeters to compare with
* Return: 1 if delimiter, 0 if no
*/
int is_delim(char ch, char *del)
{
	while (*del)
	{
		if (*del == ch)
			return (1);
		del++;
	}
	return (0);
}

/**
* _isalpha - check if any alphabetique character exists
* @ch: the character to check
* Return: 1 if alphabet, 0 if not
*/
int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
* _atoi - change a string to an integer
* @str: the string to change
* Return: the converted number on success, 0 if no number exist in the string
*/
int _atoi(char *str)
{
	int i = 0;
	unsigned int n = 0;
	int sign = 1, test = 0;

	while (str[i])
	{
		if (str[i] == 45)
		sign *= -1;
		while (str[i] >= 48 && str[i] <= 57)
		{
			test = 1;
			n = (n * 10) + (str[i] - '0');
			i++;
		}
		if (test == 1)
			break;
		i++;
	}
	n *= sign;
	return (n);
}
