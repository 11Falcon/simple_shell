#include "shell.h"

/**
 *
 */
void echo_commands(char **str)
{
	int k = 0;
	pid_t ppid;
	int last_exit = 0;
	char *path;

	if (compare(str[k], "echo"))
	{
		if (compare(str[k + 1], "$PATH"))
		{
			path = getenv("PATH");
			if (path != NULL)
			{
				_puts(path);
				_putchar('\n');
				
			}
			else
			{
				_puts("path not found");
				_putchar('\n');
			}
		}
		if (compare(str[k + 1], "$$"))
		{
			ppid = getppid();
			printf("%u\n", ppid);
		}
		if (compare(str[k + 1], "$?"))
		{
			printf("%d\n", last_exit);
		}

	}
}

