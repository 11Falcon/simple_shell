#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

typedef void (*fonction)();

/**
 * punc - structure
 * @c: pointuation
 * @description: desc
 */
typedef struct punc
{
	char c;
	char *description;
} pun_t;

/* compare.c */
int compare(const char *, const char *);

/* child.c */
void child_process_and_wait(char **, char **);
void child_process(char **, char **);
void _environ();

/* count_letters.c */
int count_letters(const char *);

/* count_words.c */
int is_punctuation(char);
int number_of_words(const char *);

/* error.c */
void error_handling(void *, const char *);

/* Falcon.c */
char **split_child1(const char *, int, char **);
char **split_(const char *);

/* get_input.c */
char *get_input();

/* merge_string.c */
char *merge(const char *, const char *);

/* puts.c */
void _puts(char *);
int _putchar(char);

/* soue.c */
char **split_child(const char *, int, char **);
char **split(const char *);

/* coments,c */
void remove_comments(char *);
/* single commands */
void single_commands(char **i_i, char *ash, char **argv);
#endif
