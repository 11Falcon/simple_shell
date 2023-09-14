#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
char **splt(char *string)
{
        char **list = malloc(sizeof(char*));
        int word = 0, first = 0, i = 0;
        if (!string)
        {
                write(STDERR_FILENO, "Error : enter a string\n", 23);
                exit(98);
        }
        while (*string)
        {
                if (*string != ' ')
                {
                        if (first)
                        {
                                list[word] = malloc(sizeof(char*));
                                first = 0;
                        }
                        else
                                list[word] = realloc(list[word], (i + 1) * sizeof(char));
                        list[word][i] = *string;
                        i++;
                        string++;
                }
                else
                {
                        while (*string == ' ')
                                string++;
                        first = 1;
                        list[word][i] = '\0';
                        word++;
                        i = 0;
                        list = realloc(list, (word + 1) * sizeof(char*));
                }
	}
	list[word] = realloc(list[word], (i+1) *sizeof(char));
	list[word] = NULL;
	return (list);
}
