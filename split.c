#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

char **split(const char *string) {
  char **list;
  int s, l, word, first = 1, i = 0;
  const char *start = string;

  if (!string) {
    return NULL;
  }

  word = number_of_words(string);
  list = malloc((word + 1) * sizeof(char*));
  if (!list) {
    error_handling(list, "Error : Memory allocation failed\n");
    return NULL;
  }

  while (*string) {
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
  }

  list[word] = NULL;
  return list;
}
