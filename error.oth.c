#include "shell.h"

/**
* _erratoi - change a string to an integer
* @str: the string to change
* Return: the integer on success, 0 if no number exist, -1 if fail
*/
int _erratoi(char *str)
{
	unsigned long int r = 0;
	int i;

	if (str[0] == '+')
		str++;
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			r = r * 10;
			r = r + (str[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}

/**
* print_error - display an error
* @info: a struct that contains arguments
* @strerr: the error string to display
* Return: nothing
*/
void print_error(info_t *info, char *strerr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(strerr);
}

/**
* print_d - display an interger
* @a: the input
* @fd: the file decscriptor
* Return: the nb of char displayed
*/
int print_d(int a, int fd)
{
	int (*__putchar)(char) = _putchar;
	unsigned int _abs, c;
	int i, cmpt = 0;

	if (fd == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (a < 0)
	{
		_abs = -a;
		__putchar('-');
		cmpt++;
	}
	else
	{
		_abs = a;
	}
	c = _abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs / i)
		{
			__putchar('0' + c / i);
			cmpt++;
		}
		c = c % i;
	}
	__putchar('0' + c);
	cmpt++;
	return (cmpt);
}

/**
* convert_number - convert a number to string
* @nb: the number to convert
* @bs: the base of the number
* @test: an interger for the test
* Return: a pointer to the converted string
*/
char *convert_number(long int nb, int bs, int test)
{
	static char *array;
	static char buf[60];
	char s = 0;
	char *p;
	unsigned long n = nb;

	if (!(test & CONVERT_UNSIGNED) && nb < 0)
	{
		n = -nb;
		s = '-';
	}
	if (test & CONVERT_LOWERCASE)
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
* remove_comments - removes the comments by replacing # with \0
* @buffer: a pointer to the comment to be removed
* Return: nothing
*/
void remove_comments(char *buffer)
{
	int i = 0;

	while (buffer[i])
	{
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
		i++;
	}
}
