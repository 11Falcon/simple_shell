#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

/* read, write buffer*/
#define READ_BUF_SIZE  1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH      -1

/* command chain */
#define CMD_NORM  0
#define CMD_OR    1
#define CMD_AND   2
#define CMD_CHAIN 3

/* convert numbers */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/* use getline system */
#define USE_GETLINE 0
#define USE_STRTOK  0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096
extern char **environ;


/* liststr linked list*/

/**
 * struct liststr - singly linked list
 * @num: the nb field
 * @str: string
 * @next: pointer to next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


/* passinfo linked list*/

/**
 * struct passinfo - has pseudo-args to pass info a function
 * @arg: string contain arguments
 * @argv: array of strings composed of arg
 * @path: the path of the current command as a string
 * @argc: args counter
 * @line_count: error count
 * @err_num: error string for exit function
 * @linecount_flag: count a line of input
 * @fname: the program filename
 * @env: local copy of environ
 * @environ: copy of environ from env
 * @history: history node
 * @alias: alias node
 * @env_changed: used if env has changed
 * @status: return status of the last exec command
 * @cmd_buf:  address of pointer to cmd_buf
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: from where to read input
 * @histcount: counter of history line nb
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	char **environ;
	list_t *history;
	list_t *alias;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}


/* buitin struct */

/**
 * struct builtin - has a buitin string plus a function
 * @type: buitin command
 * @func: related function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* myinteractive.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* builtin.c */
int _exit(info_t *);
int _cd(info_t *);
int _help(info_t *);

/* myalias.c */
int _history(info_t *);
int set_alias(info_t *, char *);
int unset_alias(info_t *, char *);
int print_alias(list_t *);
int _alias(info_t *);

/* myenviron.c */
int _env(info_t *);
char *_getenv(info_t *, const char *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* myput.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char, int);
int _putsfd(char *, int);

/* error.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* mystrn.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* getline.c */
ssize_t input_buf(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
ssize_t read_buf(info_t *, char *, size_t *);
int _getline(info_t *, char **, size_t *);
void siginthandler(int);

/* getenv.c */
char **_environ(info_t *);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);

/* myinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* myhistory.c */
char *get_history_file(info_t *);
int write_history(info_t *);
int read_history(info_t *);
int build_history_list(info_t *, char *, int);
int renumber_history(info_t *);

/* mylists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* mylists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* memory.c */
int pfree(void **);

/* mypath.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* realloc.c */
char *_memset(char *, char, unsigned int);
void sfree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* myfork.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* mytokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* mychain.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
