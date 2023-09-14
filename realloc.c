#include "shell.h"
/**
 * _realloc - realloc funtion
 * @p: char pointer
 * @old_s: old pointer
 * @new_s: new pointer
 */
void *_realloc(char *p, unsigned int old_s, unsigned int new_s)
{
	char *ptr;
	
	if (p == NULL)
		return (malloc(new_s));
	if (new_s == 0)
	{
		free(p);
		return (NULL);
	}
	if (new_s == old_s)
		return (p);
	ptr = malloc(new_s);
	if (ptr == NULL)
		return (NULL);
	if (old_s > new_s)
		old_s = new_s;
	while (old_s--)
		ptr[old_s] = ((char *)p)[old_s];
	free(ptr);
	return (p);
}
