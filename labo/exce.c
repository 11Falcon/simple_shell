#include <unistd.h>
#include <stdio.h>
int man(void)
{
	printf("i'm falcon\n");
	printf("PID: %d\n",getpid());
	char *args[] = {"./", "ls",NULL};
	if (execv(args[0], args) == -1)
		write(STDERR_FILENO, "Error\n", 6);
	printf("rrrrrrrrrrrrrrrrrrrrrrrran");
	return 0;
}
