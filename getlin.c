#include <unistd.h>
#include <stdlib.h>
int mas(void)
{
	ssize_t nread;
	char *ash = malloc(1024);

	write(STDOUT_FILENO, "$ ", 2);
	nread = read(STDIN_FILENO, ash, 1024);
	if (nread == -1)
	{
		write(STDERR_FILENO, "Error readding input \n", 19);
		return (1);
	}
	if (nread == 0)
		write(STDOUT_FILENO, "\n",1);
	write(STDOUT_FILENO, ash, nread);
	free (ash);
	return(0);
}
