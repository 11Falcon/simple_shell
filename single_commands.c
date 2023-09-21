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
		free(ash);
		free(i_i);
		exit(0);
	}
	if (compare(i_i[0], "env"))
	{
		_environ();
		return (1);
	}
	return (-1);

}
