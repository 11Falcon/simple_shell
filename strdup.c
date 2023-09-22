#include "shell.h"
/**
 * _strdup - Entry code
 * @str: input
 * Return: cahr
 */
char *_strdup(char *str)
{
	int i = 0;
	int ash = 0;
	char *c;

	if (str == NULL)
		return (0);
	while (*(str + ash))
		ash++;
	c = (char *)malloc((ash + 1) * sizeof(char));

	if (c == NULL)
		return (NULL);
	while (str[i])
	{
		*(c + i) = *(str + i);
		i++;
	}
	return (c);
}
