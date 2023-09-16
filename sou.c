#include "shell.h"
int main(void) {
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
/**
 * child_process_and_wait - same thing
 * @argv: input
 */
void child_process_and_wait(char **argv)
{
	pid_t pid = fork();
	if (pid == 0)
		child_process(argv);
	else
	{
		int status;
		wait(&status);
	}
}
/**
 * child_process - same
 * @argv: input
 */
void child_process(char **argv)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("./shell");
		exit(1);
	}
}
