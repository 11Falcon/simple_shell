#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>  // Added for string functions
#include <sys/types.h>
#include <sys/wait.h>

// Function to split input into tokens
char **split(char *input) {
    char **tokens = malloc(sizeof(char *) * 64);
    if (!tokens) {
        perror("malloc");
        exit(1);
    }

    char *token;
    int position = 0;

    token = strtok(input, " \t\n\r\a");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " \t\n\r\a");
    }
    tokens[position] = NULL;
    return tokens;
}
