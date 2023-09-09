#include "shell.h"

/**
* is_chain - check if a character is chain delimiter
* @info: a struct that contains fields
* @buffer: the list of characters
* @ptr: a pointer of the position in the buffer
* Return: 1 on success, 0 otherwise
*/
int is_chain(info_t *info, char *buffer, size_t *ptr)
{
	size_t i = *ptr;

	if (buffer[i] == '|' && buffer[i + 1] == '|')
	{
		buffer[i] = '\0';
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buffer[i] == '&' && buffer[i + 1] == '&')
	{
		buffer[i] = '\0';
		i++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buffer[i] == ';')
	{
		buffer[i] = '\0';
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*ptr = i;
	return (1);
}

/**
* check_chain - check if we continue looking for chain delim
* @info: a struct that contains fields
* @buffer: the list of characters
* @ptr: a pointer of the position in the buffer
* @idx: the position from where the buffer start
* @l: the buffer's length
* Return: nothing
*/
void check_chain(info_t *info, char *buffer, size_t *ptr, size_t idx, size_t l)
{
	size_t i = *ptr;

	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buffer[idx] = '\0';
			i = l;
		}
	}
	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buffer[idx] = '\0';
			i = l;
		}
	}
	*ptr = i;
}

/**
* replace_alias - change an alias with another in a string
* @info: a struct that contains fields
* Return: 1 on success, 0 otherwise
*/
int replace_alias(info_t *info)
{
	list_t *node;
	char *ptr;
	int i = 0;

	while (i < 10)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ptr = _strchr(node->str, '=');
		if (ptr == NULL)
			return (0);
		info->argv[0] = _strdup(ptr + 1);
		if (!info->argv[0])
			return (0);
		i++;
	}
	return (1);
}

/**
* replace_vars - change a variable in a given string
* @info: a struct that contains fields
* Return: 0
*/
int replace_vars(info_t *info)
{
	list_t *node;
	int i = 0;
	char *temp;

	while (info->argv[i])
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			temp = convert_number(info->status, 10, 0);
			replace_string(&(info->argv[i]), _strdup(temp));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			temp = convert_number(getpid(), 10, 0);
			replace_string(&(info->argv[i]), _strdup(temp));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			temp = _strchr(node->str, '=') + 1;
			replace_string(&(info->argv[i]), _strdup(temp))
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));
		i++;
	}
	return (0);
}

/**
* replace_string - replace a string with another one
* @o_str: the string to change
* @n_str: the string that takes place in the old one
* Return: 1 on success, 0 on fail
*/
int replace_string(char **o_str, char *n_str)
{
	free(*o_str);
	*o_str = n_str;
	if (*o_str)
	return (1);
	return (0);
}
