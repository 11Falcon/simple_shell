#include "shell.h"

/**
* _strncpy - copy a number of char from a string to another string
* @str1: the source string
* @str2: the destination string
* @nb: the number of character to copy
* Return: a pointer to the new character
*/
char *_strncpy(char *str2, char *str1, int nb)
{
	int i;
	char *str = str2;

	for (i = 0; i < nb - 1 && str1[i]; i++)
		str2[i] = str1[i];
	if (i < nb)
		while (i < nb)
		{
			str2[i] = '\0';
			i++;
		}
	return (str);
}

/**
* _strncat - concatenate a number of strings toghather
* @str1: string 1
* @str2: string 2
* @nb: the number of character to concatenate
* Return: pointer to the concatenated string
*/
char *_strncat(char *str1, char *str2, int nb)
{
	int i;
	int lenght = 0;

	for (i = 0; str1[i]; i++)
		lenght++;
	for (i = 0; str2[i] && i < nb; i++)
		str1[lenght + i] = str2[i];
	if (i < nb)
		str1[lenght + i] = '\0';
	return (str1);
}

/**
* _strchr - search for a character in a given string
* @str: the string where to search
* @ch: the character to search for
* Return: a pointer to the character
*/
char *_strchr(char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}
