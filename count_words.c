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