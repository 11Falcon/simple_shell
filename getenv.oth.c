#include "shell.h"

/**
* _environ - prints the environment as a string
* @info: struct that contain arguments
* Return: pointer to the environment name
*/
char **_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
* _setenv - add a variable to the environment list
* @info: struct that contains arguments
* @var: the value of the new variable
* @value: the environment value string
* Return: 0 on success, 1 if error
*/
int _setenv(info_t *info, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *ptr;

	if (!var || !value)
		return (0);
	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, var);
	_strcat(buffer, "=";
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		ptr = starts_with(node->str, var);
		if (*ptr && ptr == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}

/**
* _unsetenv - delete a varialble in the environment list
* @info: struct that contains arguments
* @var: the variable to delete
* Return: 1 on success, 0 on fail
*/
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *ptr;

	if (!node || !var)
		return (0);
	while (node)
	{
		ptr = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}
