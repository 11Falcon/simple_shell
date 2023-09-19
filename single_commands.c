#include "shell.h"
/**
 * single_commands - sambling single commands treatement
 * @i_i: list
 * @ash: char*
 */
void single_commands(char **i_i, char *ash)
{
	if (compare(i_i[0], "exit"))
	{
		free(ash);
		exit(1);
	}
	if (compare(i_i[0], "env"))
		_environ();
}
