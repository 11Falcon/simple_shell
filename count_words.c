#include "shell.h"
/**
 * is_punctuation - boolean true of false
 * @c: the chart to check
 * Return: a boolean true of false
 */
int is_punctuation(char c)
{
	punc my_punc[] = {
		{'.', "point"},
		{',', "comma"},
		{';', "semicolon"},
		{' ', "space"},
		{'\n', "newline"},
		{'\t', "Tab"},
		{0, NULL}
};
	for (int i = 0; my_punc[i].c != 0; i++)
	{
		if (my_punc[i].c == c)
			return (1);
	}
	return (0);
}
/**
 * number_of_words - count the number of words of a string
 * @string: the string to split
 * Return: the number of words
 */
int number_of_words(const char *string)
{
	int count = 0;
	int in_word = 0;

	while (*string)
	{
		if (!is_punctuation(*string))
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		else
			in_word = 0;
		string++;
	}
	return (count);
}
