#include "shell.h"
/**
 * child_process_and_wait - same thing
 * @argv: input
 * @av: args
 * Return: nothing
 */
int child_process_and_wait(char **argv, char **av)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		if ((child_process(argv, av)) == 0)
			return (1);
		else
			return (-1);
	}
	else
		wait(&status);
	return (-1);
}

/**
 * child_process - same
 * @argv: input
 * @av: args
 * Return: nothing
 */
int child_process(char **argv, char **av)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		_puts(av[0]);
		_puts(": No such file or directory");
		_putchar('\n');
		exit(-1);
	}
	else
		return (1);
	return (-1);
}

/**
 * _environ - display the environment list
 * Return: nothing
 */
void _environ(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
}
