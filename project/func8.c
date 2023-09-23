#include "shell.h"

/**
 * Auth: Emma Udeji
 * 		 Pericles Adjovi
 *
 * Description:
 * the extended functions for main.c
 */


/** par - d
 * @cd: command
 * Return: int
 */

int par(char *cd)
{
	int i;
	char *argv[] = {"env", "exit", NULL};
	char *p = NULL;

	for (i = 0; cd[i] != '\0'; i++)
	{
		if (cd[i] == '/')
			return (EX_COM);
	}
	for (i = 0; argv[i] != NULL; i++)
	{
		if (_strcmp(cd, argv[i]) == 0)
			return (INT_COM);
	}
	p = checker(cd);
	if (p != NULL)
	{
		free(p);
		return (P_COM);
	}

	return (INV_COM);
}

/**
 * execute_command - executes a command based on it's type
 * @tokenized_command: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @command_type: type of the command
 *
 * Return: void
 */
void executer(char **tokens, int ct)
{
	void (*func)(char **command);

	if (ct == EX_COM)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror(_get_env("PWD"));
			exit(2);
		}
	}
	if (ct == P_COM)
	{
		if (execve(checker(tokens[0]), tokens, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (ct == INT_COM)
	{
		func = get_(tokens[0]);
		func(tokens);
	}
	if (ct == INV_COM)
	{
		_write_(_name, STDERR_FILENO);
		_write_(": 1: ", STDERR_FILENO);
		_write_(tokens[0], STDERR_FILENO);
		_write_(": not found\n", STDERR_FILENO);
		la_statut = 127;
	}
}

/**
 * check_path - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *check_path(char *cmd)
{
	char **pa = NULL;
	char *temp, *temp2, *pc;
	char *p = _get_env("PATH");
	int i;

	if (p == NULL || _strlen(p) == 0)
		return (NULL);
	pc = malloc(sizeof(*pc) * (_strlen(p) + 1));
	_scpy(p, pc);
	pa = tokenizer(pc, ":");
	for (i = 0; pa[i] != NULL; i++)
	{
		temp2 = _strcat(pa[i], "/");
		temp = _strcat(temp2, cmd);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(pa);
			free(pc);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(pc);
	free(pa);
	return (NULL);
}

/**
 * get_func - retrieves a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*get_(char *command))(char **)
{
	int i;
	func_map ash[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(command, ash[i]._name) == 0)
			return (ash[i].func);
	}
	return (NULL);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_get_env(char *name)
{
	char **plan;
	char *p;
	char *n;

	for (plan = space; *plan != NULL; plan++)
	{
		for (p = *plan, n = name;
		     *p == *n; p++, n++)
		{
			if (*p == '=')
				break;
		}
		if ((*p == '=') && (*n == '\0'))
			return (p + 1);
	}
	return (NULL);
}
