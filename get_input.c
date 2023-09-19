#include "shell.h"

/**
 * get_input - reduce lines
 * Return: char
 */
char *get_input()
{
	int r = 0;
	char *ash = (char *)malloc(1024);

	write(STDOUT_FILENO, "($) ", 4);
	r = read(STDIN_FILENO, ash, 1024);
	if (r == -1)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		exit(1);
	}
	else if (r == 0)
	{
		write(STDOUT_FILENO, "\n", 2);
		exit(0);
	}
	return (ash);
}
