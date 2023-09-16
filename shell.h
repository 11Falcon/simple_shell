#ifndef FALCON
#define FALCON
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
typedef void (*fonction)();
/**
 * struct punc - structure
 * @c: pointuation
 * @description: desc
 */
typedef struct punc
{
	char c;
	char *description;
} pun_t;
char **split(const char *string);
void error_handling(void *ptr, const char *message);
int compare(const char *str1, const char *str2);
int subsplit(char **list, int word);
int number_of_words(const char *string);
int is_punctuation(char c);
int count_letters(const char *pointer);
char *get_input();
void child_process_and_wait(char **argv);
void child_process(char **argv);
#endif
