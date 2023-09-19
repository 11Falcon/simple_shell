#include "shell.h"
/**
 * subecho - reducing lines
 * @path char
 */
void subecho(char *path)
{
	if (path != NULL)
	{
		_puts(path);
		_putchar('\n');
	}
	else
	{
		_puts("path not found");
		_putchar('\n');
	}
}
