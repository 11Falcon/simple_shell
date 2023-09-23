#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256

int execute_command(char *command) {
    char *path_env = getenv("PATH");
    if (path_env == NULL) {
        perror("getenv");
        return 1;
    }

    char *path = strdup(path_env);
    if (path == NULL) {
        perror("strdup");
        return 1;
    }

    char *token = strtok(path, ":");
    while (token != NULL) {
        char full_path[MAX_COMMAND_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            free(path);
            return 1;
        } else if (pid == 0) {
            char *args[] = {command, NULL};
            char *envp[] = {NULL};

            if (execve(full_path, args, envp) == -1) {
                free(path);
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                free(path);
                return 0;
            }
        }
        token = strtok(NULL, ":");
    }

    free(path);

    fprintf(stderr, "./shell: %s: command not found\n", command);
    return 1;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting shell.\n");
            break;
        }

        input[strlen(input) - 1] = '\0';

        char *token = strtok(input, " ");
        while (token != NULL) {
            if (execute_command(token) != 0) {
                break;
            }
            token = strtok(NULL, " ");
        }
    }

    return 0;
}
