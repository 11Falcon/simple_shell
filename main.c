#include "shell.h"

/**
 * main - the main function
 * @ac: the argument counter
 * @av: array of strings
 * Return: 0
 */
int main(int ac, char **av)
{
	char *ash = NULL;
	char **argv = NULL, **i_i = NULL;

	while (1)
	{
		ash = get_input();
		if (ash == NULL)
		{
			free(ash);
			break;
		}

		remove_comments(ash);

		i_i = split_(ash);
		if (i_i[0] == NULL)
		{
			free(ash);
			continue;
		}
		if (echo_commands(i_i) == 1)
		{
			free(ash);
			continue;
		}
		argv = split(ash);
		if (compare(i_i[0], "exit"))
		{
			free(ash);
			exit(1);
		}
		if (compare(i_i[0], "env"))
			_environ();
		child_process_and_wait(argv, av);
		free(ash);
	}
	return (0);
	(void)ac;
}
