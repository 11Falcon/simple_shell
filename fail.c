#include "shell.h"
/**
 * fail - fail
 * @h: int
 * @ash: string
 */
void fail(int h, char *ash)
{
	if (h == -1)
	{
		free(ash);
		write(STDIN_FILENO, "\n", 2);
		write(STDIN_FILENO, "Error\n", 6);
		exit(EXIT_SUCCESS);
	}
}
