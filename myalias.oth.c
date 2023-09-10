#include "shell.h"

/**
* _history - print the list of the history line by line
* @info: a struct that contains arguments
* Return: 0
*/
int _history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
* set_alias - add an alias to the list
* @info: a struct that contains arguments
* @s: the name of the alias to add to the list
* Return: 0 on success or 1 otherwise
*/
int set_alias(info_t *info, char *s)
{
	char *ptr;

	p = _strchr(s, '=');
	if (!ptr)
		return (1);
	if (++p == NULL)
		return (unset_alias(info, s));
	unset_alias(info, s);
	if (add_node_end(&(info->alias), s, 0) == NULL)
		return (0);
	else
		return (1);
}

/**
* unset_alias - remove an alias from the list
* @info: a struct that contains arguments
* @s: the name of the alias to remove from the list
* Return: 0 on succes or 1 otherwise
*/
int unset_alias(info_t *info, char *s)
{
	list_t *node = node_starts_with(info->alias, str, '=');
	unsigned int i = 0;
	list_t *list = info->alias;

	if (node == NULL)
		return (1);
	for (; list; list = list->next)
	{
		if (list == node)
			break;
		i++;
	}
	return (delete_node_at_index(&(info->alias), i));
}

/**
* print_alias - print an alias string from the list
* @node: a struct that contains fields
* Return: 0 on success or 1 otherwise
*/
int print_alias(list_t *node)
{
	char *p = NULL;
	char *ptr = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		if (p)
		{
			ptr = node->str;
			while (ptr <= p)
			{
				_putchar(*ptr);
				ptr++;
			}
			_putchar('\'');
			_puts(p + 1);
			_puts("'\n");
			return (0);
		}
	}
	return (1);
}

/**
* _alias - dispaly all the existing alias
* @info: a struct that contains fields
* Return: 0
*/
int _alias(info_t *info)
{
	int idx = 1;
	list_t *node = info->alias;
	char *ptr = NULL;

	if (info->argc == 1)
	{
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
	}
	else
	{
		while (info->argv[i] != NULL)
		{
			p = _strchr(info->argv[i], '=');
			if (p)
				set_alias(info, info->argv[i]);
			else
				print_alias(node_starts_with(info->alias, info->argv[i], '='));
			i++;
		}
	}
	return (0);
}
