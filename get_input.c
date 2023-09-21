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
		exit(1);
	}
	r = read(STDIN_FILENO, ash, 1024);
	if (r == -1)
	{
		write(STDIN_FILENO, "Error\n", 6);
		free(ash);
		exit(1);
	}
	else if (r == 0)
	{
		exit(0);
	}
	return (ash);
}
