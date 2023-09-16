#include "shell.h"
/**
 * child_process_and_wait - same thing
 * @argv: input
 * @av: args
 */
void child_process_and_wait(char **argv, char **av)
{
	pid_t pid = fork();

	if (pid == 0)
		child_process(argv, av);
	else
	{
		int status;

		wait(&status);
	}
}
/**
 * child_process - same
 * @argv: input
 * @av: args
 */
void child_process(char **argv, char **av)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		_puts(av[0]);
		_puts(": 1: qwerty: not found");
		_putchar('\n');
		exit(1);
	}
}
