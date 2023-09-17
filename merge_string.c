#include "shell.h"
/**
 * merge - merging two strings
 * @beg: first string
 * @end: ending string
 * Return: the merging
 */
char *merge(const char *beg, const char *end)
{
	int d = count_letters(beg);
	int b = count_letters(end);
	char *merge = malloc( d + b + 1);
	int i = 0;

	if (!merge)
		return (NULL);
	while (i < d)
	{
		merge[i] = beg[i];
		i++;
	}
	i = 0;
	while (i < b)
	{
		merge[i + d] = end[i];
		i++;
	}
	merge[d + b] = '\0';
	return (merge);
}
