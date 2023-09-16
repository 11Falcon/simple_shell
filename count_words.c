#include <stdio.h>

struct punc
{
	char c;
};

struct punc my_punc[] = {
	{'.', },
	{',', },
	{';', },
	{' ', },
	{'\n', },
	{'\t', },
	{0}
};

/**
 * is_punctuation - check if a char is a punctuation mark
 * @c: the char to check
 * Return: 1 if a punctution mark, 0 if no
 */
int is_punctuation(char c)
{
	int i;

	for (i = 0; my_punc[i].c != 0; i++) {
		if (my_punc[i].c == c)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * number_of_words - count the number of words in a string
 * @string: the string who's words to count
 * Return: the number of words
 */

int number_of_words(const char *string) {
	int count = 0;
	int in_word = 0;

	while (*string)
	{
		if (!is_punctuation(*string))
		{
			if (!in_word)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		string++;
	}
	return count;
}
