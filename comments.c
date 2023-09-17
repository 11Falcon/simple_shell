#include "shell.h"

/**
* remove_comments - removes the comments by replacing # with \0
* @arg: a pointer to the comment to be removed
* Return: nothing
*/
void remove_comments(char *arg)
{
    int i = 0;

    while (arg[i])
    {
        if (arg[i] == '#' && (!i || arg[i - 1] == ' '))
        {
            arg[i] = '\0';
            break;
        }
        i++;
    }
}
