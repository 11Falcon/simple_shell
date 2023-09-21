#include "shell.h"
char **splt(char *string) {
  char **list = NULL;
  int word = 0, j;

  if (!string) {
    return NULL;
  }

  word = number_of_words(string);
  list = malloc((word + 1) * sizeof(char *));
  if (!list) {
    return NULL;
  }

  char *current_word = strtok(string, " ");
  while (current_word != NULL) {
    list[word] = current_word;
    word++;
    current_word = strtok(NULL, " ");
  }

  list[word] = NULL;
  return list;
}
