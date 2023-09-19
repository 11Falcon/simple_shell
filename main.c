#include "shell.h"

/**
 * main - the main function
 * @ac: the argument counter
 * @av: array of strings
 * Return: 0
 */
int main(int ac, char **av)
{
	char *ash = malloc(1024), **argv = NULL, **i_i = NULL;

	while (1)
	{
		ash = get_input();
		if (ash == NULL)
			break;
		remove_comments(ash);
		i_i = split_(ash);
		argv = split(ash);
		if (i_i[0] == NULL)
			continue;
		single_commands(i_i, ash, argv);
		child_process_and_wait(argv, av);
		free(ash);
	}
	return (0);
	(void)ac;
}
