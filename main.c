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
	int h, status = 0, i = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "($) ", 4);
		h = getline(&ash, &st, stdin);
		if (h == -1)
		{
			free(ash);
			write(STDIN_FILENO, "\n", 2);
			exit(EXIT_SUCCESS);
		}
		if (ash == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			free(ash);
			return (status);
		}
		remove_comments(ash);
		i_i = split_(ash, i);
		if (i_i[0] == NULL)
		{
			free(ash);
			continue;
		}
		if (isatty(STDIN_FILENO) == 0)
			if (non_interactive_func(i_i, av) != -1)
			{
				/*free(ash);*/
				free(i_i);
				continue;
			}
		if (echo_commands(i_i) == 1)
		{
			free(ash);
			continue;
		}
		glob(i_i, ash, av);
	}
	return (0);
}
