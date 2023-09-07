#include "shell.h"

/**
* pfree - free a pointer and put NULL in the address
* @p: the pointer to free
* Return: 1 on success, 0 if no
*/
int pfree(void **p)
{
	if (*p && p)
	{
		free(*p)
		* p = NULL;
		return (1);
	}
	return (0);
}
