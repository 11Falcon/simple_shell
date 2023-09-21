#include "shell.h"
/**
 * glob - glow
 * @ash: ash
 * @av: av
 */
void glob(char *ash, char **av)
{
	char **argv = split(ash);

	if (child_process_and_wait(argv, av, ash) == 1)
	{
		free(ash);
		free_i_i(argv);
	}
}
