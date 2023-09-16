#ifndef FALCON
#define FALCON
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
typedef void (*fonction)();
struct punc{
	char c;
};

char **split(const char *string);
void error_handling(void *ptr, const char *message);
int compare(const char *str1, const char *str2);
int subsplit( char **list, int word);
int number_of_words(const char *string);
int is_punctuation(char c);
int count_letters(const char *pointer);
#endif
