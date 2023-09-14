#include <unistd.h>
#include <stdio.h>
int maid(void)
{
	pid_t my_ppid, my_pid;
	my_pid = getpid();
	my_ppid = getppid();
	printf("ppid :%u\n pid : %u\n",my_ppid, my_pid);
	return (0);
}
