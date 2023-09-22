#include "shell.h"
/**
 * fail - fail
 * @h: int
 * @ash: string
 * @status: int
 * Return: int
 */
int fail(int h, char *ash, int status)
{
	if (h == -1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 2);
		free(ash);
		write(STDIN_FILENO, "\n", 2);
		exit(EXIT_SUCCESS);
		return (status);
	}
	return (status);
}
