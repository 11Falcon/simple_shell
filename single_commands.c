#include "shell.h"
/**
 * single_commands - sambling single commands treatement
 * @i_i: list
 * @ash: char*
 * Return: int
 */

int single_commands(char **i_i, char *ash)
{
	if (compare(i_i[0], "exit"))
	{
		free_i_i(i_i);
		free(ash);
		exit(0);
	}
	if (compare(i_i[0], "env"))
	{
		_environ();
		free_i_i(i_i);
		free(ash);
		return (1);
	}
	return (-1);

}
