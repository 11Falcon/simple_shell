#include "shell.h"

/**
* _strcpy - copies a string in another
* @org: the string to copy
* @cp: the copied string
* Return: pointer to the copied string
*/
char *_strcpy(char *org, char *cp)
{
	int i;

	if (org == cp || org == 0)
		return (cp);
	for (i = 0; org[i]; i++)
		cp[i] = org[i];
	cp[i] = '\0';
	return (cp);
}

/**
* _strdup - duplicate a string
* @org: the string to duplicate
* Return: pointer to the duplicated string
*/
char *_strdup(char *org)
{
	int i, j;
	char *dup;

	if (org == NULL)
		return (NULL);
	for (i = 0; org[i]; i++)
	;
	dup = malloc(sizeof(char *) * i + 1);
	if (!dup)
		return (NULL);
	for (j = 0; j < i; j++)
		dup[j] = org[j];
	return (dup);
}

/**
* _puts - a function that prints characters
* @ch: the character to print
* Return: nothing
*/
void _puts(char *ch)
{
	int i;

	if (ch == NULL)
		return;
	for (i = 0; ch[i]; i++)
		_putchar(ch[i]);
}

/**
* _putchar - print the char in the stdout
* @ch: the char to print
* Return: 1 on success, -1 on error
*/
int _putchar(char ch)
{
	int i;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, i);
	}
	i = 0;
	if (ch != BUF_FLUSH)
		buffer[i++] = ch;
	return (1);
}
