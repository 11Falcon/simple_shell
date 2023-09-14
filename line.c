#include <unistd.h>
#include <stdlib.h>
int min(void)
{
	char *ash = malloc(1024);
	int o, r, w;

	write(STDOUT_FILENO, "$ ", 2);
	r = read(STDIN_FILENO, ash, 1024);
	if (r == -1)
	{
		write(STDERR_FILENO, "Error", 5);
		free(ash);
		return (-1);
	}
	if (r == 0)
	{
		write(STDOUT_FILENO,"\n",1);
		free(ash);
		return (0);
	}
	write(STDOUT_FILENO, ash, 1024); 
	free(ash);
	return(0);
}
