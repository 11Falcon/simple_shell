#include "shell.h"

/**
 *_strcmp - compare
 *@f: input
 *@s: input
 * Return: dif
 */

int _strcmp(char *f, char *s)
{
	int i = 0;

	while (f[i] != '\0')
	{
		if (f[i] != s[i])
			break;
		i++;
	}
	return (f[i] - s[i]);
}

/**
 *_strcat - concat
 *@dest: destination
 *@src:  source
 * Return: ptr to the new string
 */

char *_strcat(char *dest, char *src)
{
	char *so =  NULL;
	int ld = _slen(dest);
	int ls = _slen(src);

	so = malloc(sizeof(*so) * (ld + ls + 1));
	_scpy(dest, so);
	_scpy(src, so + ld);
	so[ld + ls] = '\0';
	return (so);
}

/**
 *_strspn - spn
 *@s1: searched
 *@s2: used
 *Return: int
 */

int _strspn(char *s1, char *s2)
{
	int i = 0;
	int ash = 0;

	while (s1[i] != '\0')
	{
		if (_strchr(s2, s1[i]) == NULL)
			break;
		ash++;
		i++;
	}
	return (ash);
}

/**
 *_strcspn - same as the standard strcspn
 *@s1: searched
 *@s2: used
 *Return: index at which a char in str1 exists in str2
 */


int _strcspn(char *s1, char *s2)
{
	int ash = 0, i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (_strchr(s2, s1[i]) != NULL)
			break;
		ash++;
	}
	return (ash);
}

/**
 *_strchr - locates a char in a string
 *@s: string to be searched
 *@c: char to be checked
 *Return: pointer to the first occurence of c in s
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
