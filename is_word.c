#include "shell.h"
int is_exit(const char *string, const char *exit)
{
	int i = 0, count = 0;
	
	while (exit)
		count++;
	for (i = 0; i < count; i++)
	{
		if (exit[i] != string[i])
			return (0);
	}
	return (1);
}
