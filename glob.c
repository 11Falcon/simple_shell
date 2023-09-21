#include "shell.h"
/**
 * glob - glow
 * @i_i: i_i
 * @ash: ash
 * @av: av
 */
void glob(char **i_i, char *ash, char **av)
{
	char **argv;

	argv = split(ash);
	single_commands(i_i, ash);
	child_process_and_wait(argv, av);
	free_i_i(i_i);
	free_i_i(argv);
}
