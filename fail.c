#include "shell.h"
void fail(int h, char *ash)
{
	if (h == -1)
	{
		free(ash);
		write(STDIN_FILENO, "\n", 2);
		exit(EXIT_SUCCESS);
	}
}
