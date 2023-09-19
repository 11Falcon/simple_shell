#include "shell.h"

/**
* remove_comments - removes the comments by replacing # with \0
* @arg: a pointer to the comment to be removed
* Return: nothing
*/
void remove_comments(char *arg)
{
	int ii = 0;

	while (arg[ii])
	{
		if (arg[ii] == '#' && (ii == 0 || arg[ii - 1] == ' '))
		{
			arg[ii] = '\0';
			break;
		}
		ii++;
	}
}
