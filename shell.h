#ifndef _SHELL_H_
#define _SHELL_H_

#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

typedef void (*fonction)();

/**
 * struct punc - structure
 * @c: pointuation
 * @description: desc
 */
struct punc
{
	char c;
	char *description;
};

/* split.c */
char **split(const char *);

/* error.c */
void error_handling(void *, const char *);

/* compare.c */
int compare(const char *, const char *);

/* count_words.c */
int number_of_words(const char *);
int is_punctuation(char);

/* count_letter.c */
int count_letters(const char *);

/* _puts.c */
void _puts(char *);
int _putchar(char);

#endif
