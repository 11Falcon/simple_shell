#include "shell.h"

int main(void)
{
	char *ash = malloc (1024);
	char **argv;
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
