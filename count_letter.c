#include "shell.h"

int count_letters(char *pointer)
{
	int count = 0;

	while (!is_punctuation(*pointer))
	{
		count++;
		pointer++;
	}
	return (count);
}
