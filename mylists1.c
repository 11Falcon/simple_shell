#include "shell.h"

/**
* list_len - calculate the lenght of a guven list
* @list: the list who's lenght to calculate
* Return: the lenght of the list
*/
size_t list_len(const list_t *list)
{
	int i = 0;

	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

/**
* list_to_strings - gets an array of the str's of the list
* @list: a pointer to the first node of the lit to search
* Return: an array of strings
*/
char **list_to_strings(list_t *list)
{
	list_t *node = list;
	char **array;
	char *str;
	int i, j = 0, k = 0;

	i = list_len(list);
	if (!list)
		return (NULL);
	array = malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (NULL);
	while (node)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			while (j < i)
			{
				free(array[j]);
				j++;
			}
			free(array);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		array[k] = str;
		k++;
		node = node->next;
	}
	array[k] = NULL;
	return (array);
}

/**
* print_list - gets the elemets of the list
* @list: a pointer to the beginning of the list
* Return: the size of the list
*/
size_t print_list(const list_t *list)
{
	int i = 0;

	while (list)
	{
		_puts(convert_number(list->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		if (list->str)
			_puts(list->str);
		else
			_puts("(nil)");
		_puts("\n");
		i++;
		list = list->next;
	}
	return (i);
}

/**
* node_starts_with - search for the node who's str starts with a given string
* @list: a pointer to the beginning of the list
* @s: the starts of the list to search for
* @ch: the next char after s
* Return: a pointer to that specific node, NULL otherwize
*/
list_t *node_starts_with(list_t *list, char *s, char ch)
{
	char *ptr = NULL;

	while (list)
	{
		ptr = strats_with(list->str, s);
		if ((ch == -1) || (*ptr == ch) && ptr)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/**
* get_node_index - get node index
* @list: a pointer to the starts of the list
* @node: a pointer to the node who's index we need
* Return: the index of the given node, -1 otherwize
*/
ssize_t get_node_index(list_t *list, list_t *node)
{
	size_t x = 0;

	while (list)
	{
		if (list == node)
			return (x);
		x++;
		list = list->next;
	}
	return (-1);
}
