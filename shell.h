#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
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
 * struct punc - structure
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
int child_process_and_wait(char **, char **, char *);
int child_process(char **, char **, char *);
void _environ(void);

/* count_letters.c */
int count_letters(const char *);

/* count_words.c */
int is_punctuation(char);
int number_of_words(const char *);

/* error.c */
void error_handling(void *, const char *);

/* Falcon.c */
char **split_child1(const char *, int, char **);
char **split_(const char *str);
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
void section(char **list);

/* coments,c */
void remove_comments(char *);
/* single commands */
int single_commands(char *ash);
/* get line */
int get_line(void);

/* _echo.c */
char *convert_number(long int, int, int);
int echo_commands(char **);
void subecho(char *path);
/* free */
void free_i_i(char **i_i);
/* splitfunc */
char **splt(char *string);
/*glob.c */
void glob(char *ash, char **av);

/* non_interactive.c */
void space(char *);
int non_interactive_func(char **, char **);
char **custom_strtok(char *str);
int is_exit(char *string, char *exit);
/* fail.c*/
int fail(int h, char *ash, int status);
/*strdup.c */
char *_strdup(char *str);

#endif
