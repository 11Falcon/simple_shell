#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **split(const char *string) {
    if (!string) {
        write(STDERR_FILENO, "Error: Enter a string\n", 23);
        exit(98);
    }

    char **list = NULL; // Initialize the list as NULL
    int word = 0, first = 1, i = 0;
    const char *start = string;

    while (*string) {
        if (*string != ' ' && *string != '\t' && *string != '\n' && *string != '\r' && *string != '\a') {
            if (first) {
                list = realloc(list, (word + 1) * sizeof(char*));
                if (list == NULL) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
                list[word] = NULL;
                first = 0;
            }
            list[word] = realloc(list[word], (i + 2) * sizeof(char));
            if (list[word] == NULL) {
                perror("Error: Memory allocation failed");
                exit(1);
            }
            list[word][i] = *string;
            i++;
            string++;
        } else {
            while (*string == ' ' || *string == '\t' || *string == '\n' || *string == '\r' || *string == '\a')
                string++;
            if (!first) {
                list[word][i] = '\0';
                word++;
                i = 0;
                first = 1;
            }
        }
    }

    if (!first) {
        list[word][i] = '\0';
        word++;
    }

    // Allocate one extra element to store a NULL pointer at the end
    list = realloc(list, (word + 1) * sizeof(char*));
    if (list == NULL) {
        perror("Error: Memory allocation failed");
        exit(1);
    }
    list[word] = NULL;

    return list;
}
