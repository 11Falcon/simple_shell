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

#include "shell.h"
/**
 * is_exit - compare
 * @string: intpu
 * @exit: input
 * Retur: inte
 */
int is_exit(char *string, char *exit)
{
	int i = 0, count = 0, size = 0;

	while (exit[count])
		count++;
	while (string[size])
		size++;
	if (count > size)
		return (0);
	for (i = 0; i < count; i++)
	{
		if (exit[i] != string[i])
			return (0);
	}
	return (1);
}
