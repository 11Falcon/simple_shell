#include "shell.h"

/**
* _env - display the environment list
* @info: a struct that contains arguments
* Return: 0
*/
int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
* _getenv - search for a variable in the environment list
* @info: a struct that contains arguments
* @var: the variable to search for
* Return: a pointer to the variable, or NULL if it's not there
*/
char *_getenv(info_t *info, const char *var)
{
	list_t *node = info->env;
	char *tok;
	
	while (node)
	{
		tok = starts_with(node->str, var);
		if (tok != NULL)
			return (tok);
		node = node->next;
	}
	return (NULL);
}

/**
* _mysetenv - adds a new variable to the environment list
* @info: a struct that contanins arguments
* Return: 0 on success, 1 on fail
*/
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
* _myunsetenv - delets a variable from the environment list
* @info: a struct that contains arguments
* Return: 0
*/
int _myunsetenv(info_t *info)
{
	int i = 1;
	
	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	while (i <= info->argc)
	{
		_unsetenv(info, info->argv[i]);
		i++;
	}
	return (0);
}

/**
* populate_env_list - populate the list of the environment
* @info: a struct that contains arguments
* Return: 0
*/
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i = 0;
	
	while (environ[i] != '\0')
	{
		add_node_end(&node, environ[i], 0);
		i++
	}
	info->env = node;
	return (0);
}
