#include "shell.h"

/**
* clear_info - inisialize the fields in the struct info
* @info: a struct that contain arguemnts
* Return: nothing
*/
void clear_info(info_t *info)
{
	info->argv = NULL;
	info->arg = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
* set_info - set the struct info with values
* @info: a struct that contain arguemnts
* @array_v: an array of arguments
* Return: nothing
*/
void set_info(info_t *info, char **array_v)
{
	int i = 0;

	info->fname = array_v[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, "\t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		while (info->argv && info->argv[i])
			i++;
		info->argc = i;
		replace_alias(info);
		replace_vars(info);
	}

}

/**
* free_info - frees the fields of the struct info
* @info: a struct that contains arguments
* @check: a checker has true if all fields are freed
* Return: nothing
*/
void free_info(info_t *info, int check)
{
	sfree(info->argv);
	info->path = NULL;
	info->argv = NULL;

	if (check)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		sfree(info->environ);
		info->environ = NULL;
		pfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

