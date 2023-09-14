#include "shell.h"

/**
* _exit - exit the shell
* @info: a struct that contains argumets
* Return: an integer
*/
int _exit(info_t *info)
{
	int x;

	if (info->argv[1] != '\0')
	{
		x = _erratoi(info->argv[1]);
		if (x == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
* _cd - go to another directory
* @info: a struct that contains arguments
* Return: 0
*/
int _cd(info_t *info)
{
	return (0);
}

/**
* _help - a function that calls HELP
* @info: a struct that contains arguments
* Return: 0
*/
int _help(info_t *info)
{
	char **array;

	array = info->argv;
	_puts("help call works. Function not yet implemented\n");
	if (0)
		_puts(*array);
	return (0);
}
