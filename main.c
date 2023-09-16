#include "shell.h"
/**
 * main - the core function
 * Return: int
 */
int main(void)
{
	char *ash = malloc(1024), **argv;

	while (1)
	{
		ash = get_input();
		argv = split(ash);
		if (argv[0] == NULL)
			continue;
		if (compare(argv[0], "exit"))
		{
			free(ash);
			exit(1);
		}
		child_process_and_wait(argv);
		free(ash);
	}
	return (0);
}
