#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - simple shell core
 * Return: int
 */
int main(void)
{
	char *ash = malloc(1024), **argv;
	pid_t pid;

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
				perror("./shell");
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
