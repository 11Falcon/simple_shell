#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int file_exists(const char *file)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	int exists = 0;

	if (path == NULL)
		return 0;
	if (path_copy == NULL)
	{
		perror("strdup");
		return 0;
	}
	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(file) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return 0;
		}
		sprintf(full_path, "%s/%s", dir, file);
		if (access(full_path, F_OK) == 0)
		{
			exists = 1;
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return exists;
}
