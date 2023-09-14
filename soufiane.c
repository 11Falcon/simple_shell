#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int compareStrings(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return 0; // Strings are different
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0'); // Check if both strings are at the end
}

int main(void) {
    char *ash = malloc(1024);
    char *input;
    char **argv;

    while (1) {
        free(ash);
        int r;
        pid_t pid;

        ash = (char *)malloc(1024);
        if (!ash) {
            perror("malloc");
            exit(1);
        }

        write(STDOUT_FILENO, "($) ", 4);
        r = read(STDIN_FILENO, ash, 1024);
        if (r == -1) {
            write(STDOUT_FILENO, "Error\n", 6);
            continue;
        } else if (r == 0) {
            write(STDOUT_FILENO, "\n", 1);
            continue;
        }

        argv = split(ash);
	if (argv[0] == NULL)
	{
		continue;
	}

        input = "^D"; // Assuming you want to exit with Ctrl-D

        if (compareStrings(argv[0], input)) {
            printf("bye\n");
            free(ash);
            free(argv);
            exit(0);
        }

        pid = fork();
        if (pid == -1) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            if (execve(argv[0], argv, NULL) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            int status;
            wait(&status);
        }

        free(argv);
    }

    return 0;
}
