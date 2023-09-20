#include "shell.h"

/**
 * get_input - reduce lines
 * Return: char
 */
char *get_input()
{
	int r;
	char *ash = (char *)malloc(1024);

	if (ash ==  NULL)
	{
		error_handling(ash, "Error: memory allocation failed\n");
		free(ash);
		return (NULL);
	}
	memset(ash, 0, 1024);
	r = read(STDIN_FILENO, ash, 1024);
	if (r == -1)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		free(ash);
		exit(1);
	}
	else if (r == 0)
	{
		write(STDOUT_FILENO, "\n", 2);
		free(ash);
		exit(0);
	}
	return (ash);
}
/**remove_newlines_ptr - remove it
 * @string: nice
 */
void remove_newlines_ptr(char *string)
{
	char *p = string;
	while (*p != '\0')
	{
		if (*p == '\n')
		{
			*p = '\0';
		}
		p++;
	}
}
