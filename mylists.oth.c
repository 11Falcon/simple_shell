#include "shell.h"

/**
* add_node - add a new node at the beginning of the list
* @list: a pointer to the beginning of the list
* @str: the first field of the struct
* @num: the second field of the struct
* Return: a pointer to the head of the new list
*/
list_t *add_node(list_t **list, const char *str, int num)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (!list || !new_node)
	{
		return (NULL);
	}
	_memset((void *)new_node, '\0', sizeof(list_t));

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->num = num;

	new_node->next = *list;
	*list = new_node;
	return (new_node);
}

/**
* add_node_end - add a new node at the end of the list
* @list: a pointer to the beginning of the list
* @str: the first champ of the struct
* @num: the second champ of the struct
* Return: a pointer to the new node, NULL otherwize
*/
list_t *add_node_end(list_t **list, const char *str, int num)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *node = *list;

	if (!list || !new_node)
		return (NULL);

	_memset((void *)new_node, '\0', sizeof(list_t));

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->num = num;

	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = new_node;
	}
	else
		*list = new_node;
	return (new_node);
}

/**
* print_list_str - display the str champ of evevry node in the list
* @list: a pointer to the beginning of the list
* Return: the number of elements in the given list
*/
size_t print_list_str(const list_t *list)
{
	size_t j = 0;

	for (; list; list = list->next)
	{
		if (list->str)
			_puts(list->str);
		else
			_puts("(nil)");
		_puts("\n");
		j++;
	}
	return (j);
}

/**
* delete_node_at_index - deletes a node at specific place
* @list: a pointer to the beginning of the list
* @idx: the index of the node to erase
* Return: 1 on success, 0 otherwize
*/
int delete_node_at_index(list_t **list, unsigned int idx)
{
	list_t *node = *list;
	list_t *ptr = NULL;
	unsigned int i = 0;

	if (*list == NULL)
		return (0);
	if (idx == 0)
	{
		*list = (*list)->next;
		free(node->str);
		free(node);
		return (1);
	}
	while (i < idx - 1)
	{
		if (!node || !node->next)
			return (0);
		node = node->next;
		i++;
	}
	ptr = node->next;
	node->next = ptr->next;
	free(ptr->str);
	free(ptr);
	return (1);
}

/**
* free_list - frees all the elements in the list
* @list: a pointer to the beginning of the list
* Return: nothing
*/
void free_list(list_t **list)
{
	list_t *head = *list;
	list_t *node, *next_n;

	if (!list || !*list)
		return;
	node = head;
	while (node)
	{
		next_n = node->next;
		free(node->str);
		free(node);
		node = next_n;
	}
	*list = NULL;
}
