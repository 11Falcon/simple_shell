#include "shell.h"

/**
 *environnement - environnement
 *@tokens: input
 */

void environnement(char **tokens __attribute__((unused)))
{
	int o_o;

	for (o_o = 0; space[o_o] != NULL; o_o++)
	{
		_write_(space[o_o], STDOUT_FILENO);
		_write_("\n", STDOUT_FILENO);
	}
}
/**
 * exiting - quit
 * @tokens: input
 */

void exiting(char **tokens)
{
	int num = 0, argv, stat;

	while (tokens[num] != NULL)
		num++;
	if (num == 1)
	{
		free(tokens);
		free(lin);
		free(comm_);
		exit(stat);
	}
	else if (num == 2)
	{
		argv = _ati(tokens[1]);
		if (argv == -1)
		{
			_write_(_name, STDERR_FILENO);
			_write_(": 1: exit: Illegal number: ", STDERR_FILENO);
			_write_(tokens[1], STDERR_FILENO);
			_write_("\n", STDERR_FILENO);
			stat = 2;
		}
		else
		{
			free(lin);
			free(tokens);
			free(comm_);
			exit(argv);
		}
	}
	else
		_write_("more than one argument\n", STDERR_FILENO);
}
