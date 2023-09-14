#include "shell.h"

/**
* _memset - add constant bytes to memory
* @ptr: pointer to the memory
* @b: the type of bytes to fill with
* @nb: the number of bytes to fill the memory
* Return: pointer to the filled memory
*/
char *_memset(char *ptr, char b, unsigned int nb)
{
	unsigned int i = 0;
	
	while (i < nb)
	{
		ptr[i] = b;
		i++;
	}
	return (ptr);
}

/**
* sfree - free a string
* @str: a string that contain strings
* Return: nothing
*/
void sfree(char **str)
{
	char **s = str;

	if (str == NULL)
		return;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(s);
}

/**
* _realloc - reallocat an area in memory
* @p: pointe to the memory to reallocat
* @old_size: the old size of the memory area
* @new_size: the new size of the memory area
* Return: pointer to the reallocated memory area
*/

void *_realloc(char *p, unsigned int old_size, unsigned int new_size)
{
	char *ptr;
	
	if (p == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(p);
		return (NULL);
	}
	if (new_size == old_size)
		return (p);
	ptr = malloc(new_size);
	if (ptr == NULL)
		return (NULL);
	if (old_size > new_size)
		old_size = new_size;
	while (old_size--)
		ptr[old_size] = ((char *)p)[old_size];
	free(ptr);
	return (p);
}
