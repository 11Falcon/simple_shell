#include "shell.h"
/**
 * single_commands - sambling single commands treatement
 * @ash: char*
 * Return: int
 */

int single_commands(char *ash)
{
	char *image = ash;

	while(is_punctuation(*image))
		image++;
	if (is_exit(image, "exit"))
	{
		free(ash);
		exit(0);
	}
	if (is_exit(image, "env"))
	{
		_environ();
		free(ash);
		return (1);
	}
	return (-1);

}
