#include "shell.h"

/**
* _eputs - display an input of string
* @s: the string to display
* Return: nothing
*/
void _eputs(char *s)
{
	int i = 0;

	if (!s)
		return;
	for (i = 0; s[i] != '\0'; i++)
		_eputchar(s[i]);
}

/**
* _eputchar - display a char in stderr
* @ch: the char to display
* Return: 1 if success
*/
int _eputchar(char ch)
{
	int i = 0;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
		write(2, buffer, i);
	i = 0;
	if (ch != BUF_FLUSH)
		buffer[i++] = ch;
	return (1);
}

/**
* _putfd - put a character in a specific place fd
* @ch: the character
* @fd: the file where to write
* Return: 1 on success, -1 on fail
*/
int _putfd(char ch, int fd)
{
	int i = 0;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
		write(fd, buffer, i);
	i = 0;
	if (ch != BUF_FLUSH)
		buffer[i++] = ch;
	return (1);
}

/**
* _putsfd - display the string
* @s: the string to print
* @fd: the file where to write
* Return: 1 on success, -1 on fail
*/
int _putsfd(char *s, int fd)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i = i + _putfd(*s, fd);
		s++;
	}
	return (i);
}
