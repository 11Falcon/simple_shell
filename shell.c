#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

/**
 * main - the main function
 * @ac: the argument counter
 * @av: array of strings
 * Return: 0
 */

int main(int ac, char **av)
{
	int fd;
	char *ash = malloc (1024);
	char **argv;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY, 0644);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit (126);
			if (errno == ENOENT)
			{
				_puts(av[0]);
				_puts(": 0: Can't open ");
				_puts(av[1]);
				_putchar('\n');
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}

	while (1)
	{
		int r;
		pid_t pid;
		write(STDOUT_FILENO, "($) ", 4);
		ash = (char *)malloc(100);
		r = read(STDIN_FILENO, ash, 1024);
		if (r == -1)
		{
			write(STDOUT_FILENO, "Error\n", 6);
			continue;
		}
		else if (r == 0)
		{
			write(STDOUT_FILENO, "\n", 2);
			continue;
		}
		argv = split(ash);
		if (argv[0] == NULL)
			continue;
		if (compare(argv[0], "exit"))
		{
			free(ash);
			exit (1);
		}
		pid = fork();
		if (pid == -1)
		{
			write(STDERR_FILENO, "Error\n", 6);
			continue;
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				_puts(av[0]);
				_puts(": 1: qwerty: not found");
				_putchar('\n');
				exit(1);
			}
		}
		else
		{
			int status;
			wait(&status);
		}
		free(ash);
	}
	return (0);
}
