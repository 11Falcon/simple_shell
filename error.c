#include "shell.h"

/**
 * error_handling - handle erro
 * @ptr: condition
 * @message: the message to return
 * Return: nothing
 */
void error_handling(void *ptr, const char *message)
{
	if (ptr == NULL)
	{
		write(STDERR_FILENO, message, 30);
		exit(1);
	}
}
