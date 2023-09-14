#include "shell.h"

/**
* _strlen - return the lenght of the string
* @str: the string to mesure
* Return: the lenght of the string
*/
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/**
* _strcmp - compare two strings
* @str1: string 1
* @str2: string 2
* Return: 1 when str1 > str2, 0 when str1 == str2, -1 when str1 < str2
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return (1);
	else if (*str1 < *str2)
		return (-1);
	else
		return (0);
}

/**
* strats_with -  search for a substring in string
* @s: the string to search in
* @substr: the substring to search for
* Return: the address of the substring or NULL
*/
char *starts_with(char *s, char *substr)
{
	int i;

	while (*s != '\0')
	{
		while (*substr != '\0' && *s == *substr)
		{
			s++;
			substr++;
		}
		if (*substr == '\0')
			return (substr);
		s++;
	}
	return (NULL);
}

/**
* _strcat - concatenate two strings
* @str1: string nb 1
* @str2: string nb 2
* Return: address of the concatenated the string
*/
char *_strcat(char *str1, char *str2)
{
	char *deststr1 = str1;

	while (*str1)
		str1++;
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = *str2;
	return (deststr1);
}
