#include "shell.h"

/**
 * main - the main function
 * @ac: the argument counter
 * @av: array of strings
 * Return: 0
 */
int main(int ac, char **av)
{
	size_t st = 0;
	char *ash = NULL, **i_i;
	int h, status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "($) ", 4);
		h = getline(&ash, &st, stdin);
		if (h == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			return (status);
		}
		fail(h, ash);
		if (ash == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			free(ash);
			return (status);
		}
		remove_comments(ash);
		i_i = split_(ash);
		if (i_i[0] == NULL)
			continue;
		if (isatty(STDIN_FILENO) == 0)
			if (non_interactive_func(i_i, av) != -1)
			{
				free(i_i);
				continue;
			}
		if (echo_commands(i_i) == 1)
		{
			free(ash);
			continue;
		}
		if (single_commands(i_i, ash) == 1)
			continue;
		glob(ash, av);
	}
	return (0);
	(void)ac;
}
