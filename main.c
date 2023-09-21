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
	char *ash = NULL, **argv, **i_i;
	int j, h, status = 0;

	(void)ac;

	while (1)
	{
		if (isatty(0) == 1)
			write(1, "($) ", 4);
		h = getline(&ash, &st, stdin);
		if (h == -1)
		{
			free(ash);
			write(0, "\n", 2);
			perror("error");
			exit(EXIT_SUCCESS);
		}
		if (ash == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			free(ash);
			return (status);
		}
		remove_comments(ash);
		i_i = split_(ash);
		if (i_i[0] == NULL)
		{
			/*free(ash);*/
			continue;
		}
		if (echo_commands(i_i) == 1)
		{
			/*free(ash);*/
			continue;
		}
		argv = split(ash);
		single_commands(i_i, ash);
		child_process_and_wait(argv, av);
		for (j = 0; i_i[j]; j++)
			free(i_i[j]);
		free(i_i);
		for (j = 0; argv[j] != NULL; j++)
			free(argv[j]);
		free(argv);
		/*free(ash);*/
	}
	return (0);
}
