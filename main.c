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
	int h, status = 0;
	/*com _structur;*/

	while (1)
	{
		char *ash = NULL, **i_i;

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "($) ", 4);
		h = getline(&ash, &st, stdin);
		fail(h, ash, status);
		if (ash == NULL)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 2);
			free(ash);
			return (status);
		}
		if (single_commands(ash) == 1)
			continue;
		remove_comments(ash);
		i_i = split_(ash);
		if (i_i[0] == NULL)
			continue;
		/**if (isatty(STDIN_FILENO) == 0)
		{
			_structur = non_interactive_func(i_i, av);
			if (_structur.execveResult == -1)
			{
				free(_structur.command);
				free(i_i);
				continue;
			}
		}
		*/
		if (echo_commands(i_i) == 1)
		{
			free(ash);
			continue;
		}
		glob(ash, av);
	}
	return (0);
	(void)ac;
}
