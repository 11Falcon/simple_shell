#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int vowe(void)
{
	pid_t pid;
	pid_t my_pid;
	int i = 0;
	char *argv[] ={"/bin/ls", "-l", "/tmp", NULL};
	int state;

	while (i < 5)
	{
		pid = fork();
		my_pid = getpid();
		if (pid == -1)
		{
			write(STDOUT_FILENO, "Error\n", 6);
			return (-1);
		}
		if (pid == 0)
		{
			printf("the pid of the running child is :%u\n", my_pid);
			fflush(stdout);
			if (execve("/bin/ls", argv, NULL) == -1)
			{
				write(STDERR_FILENO, "Error\n", 6);
				return (-1);
			}
		}
		else
		{
			wait(&state);
		}
		i++;
	}
	return (1);
}
