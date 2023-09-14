#ifndef FALCON
#define FALCON
#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

char **split(const char *string);
void error_handling(void *ptr, const char *message);
int compare(const char *str1, const char *str2);
int subsplit( char **list, int word);
void *_realloc(char *p, unsigned int old_s, unsigned int new_s);
#endif
