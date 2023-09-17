#include "shell.h"

/**
 * split_child - reduce lines
 * @string: input
 * @i: index of the current word
 * @list: the list of words
 * Return: a list of words
 */
char **split_child(const char *string, int i, char **list)
{
        int l, s;

        if (!string || !list) {
                return NULL;
        }

        if (!is_punctuation(*string)) {
                s = 0;
                l = count_letters(string);
                list[i] = malloc(l + 1);
                if (!list[i]) {
                        error_handling(list, "Error : Memory allocation failed\n");
                        return NULL;
                }
                while (s < l) {
                        list[i][s] = *string;
                        s++;
                        string++;
                }
                list[i][l] = '\0';
                i++;
        } else {
                while (is_punctuation(*string)) {
                        string++;
                }
        }

        return list;
}

/**
 * split - splitting a string to words
 * @string: the sentence to split
 * Return: a list of words
 */
char **split(const char *string)
{
        char **list;
        int word, i = 0;

        if (!string) {
                return NULL;
        }

        word = number_of_words(string);
        list = malloc((word + 1) * sizeof(char *));
        if (!list) {
                error_handling(list, "Error : Memory allocation failed\n");
                return NULL;
        }

        while (*string) {
                split_child(string, i, list);
                if (!list) {
                        return NULL;
                }
		i++;
        }

        list[word] = NULL;
        return list;
}
int main() {
  char **list;
  char *string = "Hello, world! This is a new line.";

  list = split(string);

  if (list == NULL) {
    printf("Error: Failed to split the string.\n");
    exit(1);
  }

  for (int i = 0; list[i] != NULL; i++) {
    printf("%s\n", list[i]);
  }

  free(list);

  return 0;
}
