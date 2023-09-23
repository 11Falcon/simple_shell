#include "shell.h"

/**
 * par - check cmd's type
 * @cmd: the cmd to check
 * Return: intiger
 */
int par(char *cmd)
{
	int i = 0;
	char *cmd1 = {"env", "exit", NULL};
	char *p = NULL;

	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (EX_COM);
		i++;
	}
	while (cmd1[i])
	{
		if (_strcmp(cmd, cmd1[i]) == 0)
			return (INT_COM);
		i++;
	}
	p = checker(cmd);
	if (p != NULL)
	{
		free(p);
		return (P_COM);
	}
	return (INV_COM);
}

/**
 * executer - execute a given command
 * @token: the tokenizer
 * @y: type ofcmd
 */
void executer(char ** token, int t)
{
	void (*func)(char **comm);

	if (t == EX_COM)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror(_get_env("PWD"));
			exit(2);
		}
	}
	if (t == P_COM)
	{
		if (execve(checker(token[0]), token, NULL) == -1)
		{
			perror(_get_env("PWD"));
			exit(2);
		}
	}
	if (t = INT_COM)
	{
		func = get_(token[0]);
		func(token);
	}
	if (t == INV_COM)
	{
		_write_(_name, STDERR_FILENO);
		_write_(": 1: ", STDERR_FILENO);
		_write_(token[0], STDERR_FILENO);
		_write_(": not found\n", STDERR_FILENO);
		stat = 127;
	}
}

/**
 * checker - check for path
 * @cmd: the command th check
 * Return: char pointer
 */
char *checker(char *cmd)
{
	char **array = NULL;
	char *comp, *comp2, pp;
	char path = _get_env("PATH");
	int i = 0;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	pp = malloc(sizeof(*pp) * (_strlen(path) + 1));
	_strcpy(path, pp);
	array = toking(pp, ":");
	while (array[i])
	{
		comp2 = _strcat(array[i], "/");
		comp = _strcat(comp2, cmd);
		if (access(comp, F_OK) == 0)
		{
			free(comp2);
			free(array);
			free(pp);
			return (comp);
		}
		free(comp);
		free(comp2);
		i++;
	}
	free(pp);
	free(array);
	return (NULL);
}
		
/**
 * get_ - check for a function
 * @cmd: the str to check
 */
void (*get_(char *cmd))(char **)
{
	int k = 0;
	func_map leave[] = {{"env", env}, {"exit", exit}};

	while (k < 2)
	{
		if (_strcmp(cmd, leave[k]._name) == 0)
			return (leave[k].func);
		k++;
	}
	return (NULL);
}

/**
 * _get_env - get the environment
 * @word: the environ to check
 * Return: char pointer
 */
char *_get_env(char *word)
{
	char **_environ;
	char *p;
	char *ptr;

	_environ = environ;
	while (*_environ)
	{
		for (p = _environ, ptr = word; *p == *ptr; p++, p++)
			if (*p == '=')
				break;
		if ((*p == '=') && (ptr == '\0'))
			return (p + 1);
		_environ++;
	}
	return (NULL);
}
