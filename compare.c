#include "shell.h"
/**
 * compare - compare to strings
 * @str1: first string
 * @str2: second string
 * Return: int
 */
int compare(const char *str1, const char *str2)
{
	int  i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	else
		return (0);
}
