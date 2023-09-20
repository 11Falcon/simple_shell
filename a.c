#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        char *argv[] = { "/bin/sh", "-c", command, NULL };
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    if (isatty(STDIN_FILENO)) {
        // Interactive mode
        char *input;
        size_t len = 0;

        while (1) {
            printf("($)\n");
            ssize_t nread = getline(&input, &len, stdin);
            if (nread == -1 || strcmp(input, "exit\n") == 0) {
                free(input);
                break;
            }
            // Remove newline character
            if (nread > 0 && input[nread - 1] == '\n') {
                input[nread - 1] = '\0';
            }
            execute_command(input);
        }
    } else {
        // Non-interactive mode
        char *input = NULL;
        size_t len = 0;

        while (getline(&input, &len, stdin) != -1) {
            // Remove newline character
            size_t input_len = strlen(input);
            if (input_len > 0 && input[input_len - 1] == '\n') {
                input[input_len - 1] = '\0';
            }
            execute_command(input);
        }

        free(input);
    }

    return 0;
}
