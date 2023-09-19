#include "shell.h"

/**
 * convert_number - convert an integer int string
 * @nb: the integer to convert
 * @bs: the base of the number
 * @test: for testing
 * Return: the converted string
 */
char *convert_number(long int nb, int bs, int test)
{
	static char *array;
	static char buf[60];
	char s = 0;
	char *p;
	unsigned long n = nb;

	if (!(test & 2) && nb < 0)
	{
		n = -nb;
		s = '-';
	}
	if (test & 1)
		array = "0123456789abcdef";
	else
		array = "0123456789ABCDEF";
	p = &buf[59];
	*p = '\0';
	do {
		*--p = array[n % bs];
		n = n / bs;
	} while (n != 0);
	if (s != '\0')
		*--p = s;
	return (p);
}

/**
 * echo_commands - handle the echo $PATH | $$ | $? commands
 * @str: the string that has the command to handle
 * Return: nothing
 */
int echo_commands(char **str)
{
	int k = 0;
	pid_t ppid;
	char *path;

	if (compare(str[k], "echo"))
	{
		if (compare(str[k + 1], "$PATH"))
		{
			path = getenv("PATH");
			subecho(path);
			return (1);
		}
		else if (compare(str[k + 1], "$$"))
		{
			ppid = getppid();
			_puts(convert_number(ppid, 10, 0));
			_putchar('\n');
			return (1);
		}
		else if (compare(str[k + 1], "$?"))
		{
			_puts(convert_number(WEXITSTATUS(system(NULL)), 10, 0));
			_putchar('\n');
			return (1);
		}
		else if (str[k + 1] == NULL)
		{
			_putchar('\n');
			return (1);
		}
	}
	return (0);
}
