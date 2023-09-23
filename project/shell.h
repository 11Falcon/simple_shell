#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EX_COM 1
#define INT_COM 2
#define P_COM 3
#define INV_COM -1

#define min(a, b) (((a) < (b)) ? (a) : (b))

/**
 *struct map - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

typedef struct map
{
	char *_name;
	void (*func)(char **comm);
} func_map;

extern char **space;
extern char *lin;
extern char **comm_;
extern char *_name;
extern int la_statut;
/*helpers*/
char **toking(char *input, char *dl);
void _write_(char *str, int where);
void sup_n_line(char *str);
int _slen(char *);
void _scpy(char *, char *);

/*helpers2*/
int _strcmp(char *f, char *s);
char *_strcat(char *dest, char *src);
int _strspn(char *s1, char *s2);
int _strcspn(char *s1, char *s2);
char *_strchr(char *s, char c);
/*helpers3*/
char *_strtok_r(char *str, char *dl, char **ash);
int _ati(char *s);
void *_realloc(void *ptr, unsigned int os, unsigned int ns);
void ctl_c_(int ash);
void comment(char *ipt);

/*utils*/
int par(char *);
void executer(char **, int);
char *checker(char *);
void (*get_(char *))(char **);
char *_get_env(char *);

/*built_in*/
void environnement(char **);
void exiting(char **tokens);

/*main*/
extern void non_inter(void);
extern void init_(char **current_command, int type_command);

#endif /*SHELL_H*/
