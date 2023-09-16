#include "shell.h"

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
	return (write(1, &ch, 1));
}
