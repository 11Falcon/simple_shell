#include "shell.h"
/**
* is_cmd - check if a given file is executable
* @info: a struct with arguments
* @p: the path to the file
* Return: 1 on success, 0 otherwise
*/
int is_cmd(info_t *info, char *p)
{
	struct stat st;
	(void)info;

	if (!p || stat(p, &st) != 0)
		return (0);
	return (st.st_mode & S_IFREG ? 1 : 0);
}
/**
* dup_chars - duplicate a character
* @str: the given string
* @f_idx: the first index to start with
* @l_idx: the last index to end with
* Return: a pointer to the buffer
*/
char *dup_chars(char *str, int f_idx, int l_idx)
{
	static char buffer[1024];
	int k = 0;
	int i = f_idx;

	while (i < l_idx)
	{
		if (str[i] != ':')
			buffer[k++] = str[i];
		i++;
	}
	buffer[k] = '\0';
	return (buffer);
}

/**
* find_path - finds the cmd in the given string
* @info: a struct contains arguments
* @str: the given path string
* @cmd: the cmd to find
* Return: a pointer to the path, NULL otherwise
*/
char *find_path(info_t *info, char *str, char *cmd)
{
	int i, j;
	char *ptr;
	
	if (!str)
		return (NULL);
	if (starts_with(cmd, "/") && (_strlen(cmd) > 2))
		if (is_cmd(info, cmd))
			return (cmd);
	i = 0;
	j= 0;
	while (1)
	{
		if (str[i] == ':' || !str[i])
		{
			ptr = dup_chars(str, j, i);
			if (!*ptr)
				_strcat(ptr, cmd);
			else
			{
				_strcat(ptr, "/");
				_strcat(ptr, cmd);
			}
			if (is_cmd(info, ptr))
				return (ptr);
			if (!str[i])
				break;
			j = i;
		}
		i++;
	}
	return (NULL);
}
