#include "shell.h"
struct punc my_punc[] = {
	{'.', },
	{',', },
	{';', },
	{' ', },
	{'\n', },
	{'\t', },
	{0}
};
int number_of_words(char *string)
{
	int i = 0, actual_is_ponc = 0;
	int count = 0, prec_is_ponc = 0, stop;
	while (string)
	{
		i = 0;
		stop = 0;
		while (my_punc[i].c)
		{
			if ((my_punc[i].c) == *string)
			{
				prec_is_ponc = actual_is_ponc;
				string ++;
				actual_is_ponc = 1;
				stop = 1;
			}
			i++;
		}
		if (stop == 0)
		{
			string++;
			actual_is_ponc = 0;
		}
		if (!actual_is_ponc && prec_is_ponc)
			count++;
	}
	return (count);
}

