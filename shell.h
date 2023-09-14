#ifndef FALCON
#define FALCON
char **split(const char *string);
void error_handling(void *ptr, const char *message);
int compare(const char *str1, const char *str2);
void subsplit( char **list, int word, int first);
#endif
