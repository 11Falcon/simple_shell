#include "shell.h"
/**
 * count_letters - number of letters in a word
 * @pointer: the poiner of the first letter of the word
 * Return: the number of letters
 */
int count_letters(const char *pointer)
{
	int count = 0;

	while (!is_punctuation(*pointer))
	{
		count++;
		pointer++;
	}
	return (count);
}
