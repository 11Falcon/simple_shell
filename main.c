#include "shell.h"

/**
 * main - the main function
 * @ac: the argument counter
 * @av: array of strings
 * Return: 0
 */
int main(int ac, char **av)
{
	char *ash = malloc(1024), **argv, **i_i;

	while (1)
	{
		ash = get_input();
		if (ash == NULL)
		       break;
		remove_comments(ash);

		i_i = split_(ash);
		echo_commands(i_i);

		argv = split(ash);
		if (i_i[0] == NULL)
			continue;
		if (compare(i_i[0], "exit"))
		{
			free(ash);
			exit(1);
		}
		if (compare(i_i[0], "env"))
			_environ(argv);
		child_process_and_wait(argv, av);
		free(ash);
	}
	return (0);
	(void)ac;
}