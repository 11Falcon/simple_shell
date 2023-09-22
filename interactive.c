#include "shell.h"

/**
 * space - space
 * @s: input
 */
void space(char *s)
{
	int i = 0, j = 0;
	int l = 0;

	while (s[l])
		l++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (i < l)
		s[j++] = s[i++];
	s[j] = '\0';
	i = j - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
	{
		s[i] = '\0';
		i--;
	}
}

/**
 * non_interactive_func - dealing with it
 * @str: str
 * @av: av
 * Return: int
 */
struct CommandResult non_interactive_func(char **str, char **av)
{
	struct CommandResult result;
        char *cmd;
        pid_t pid;
        int status;
        int cmpt = 0;
        int i = 0;

	result.command = NULL;
	result.execveResult = 0;
        for (; str[cmpt]; cmpt++)
                ;
        while (i < cmpt)
        {
                cmd = _strdup(str[i]);
                space(cmd);
                if (cmd[0] != '\0')
                {
                        pid = fork();
                        if (pid == 0)
                        {
                                if (execve(cmd, av, NULL) == -1)
                                {
					result.execveResult = -1;
					result.command = NULL;
                                        free(cmd);
                                        continue;
                                }
                                else
                                {
					result.execveResult = execve(cmd, av, NULL);
					result.command = cmd
                                        return (result);
                                }
                        }
                        else
                        {
                                wait(&status);
                                free(cmd);
                        }
                }
                i++;
        }
        return (result);
}
/**
 * int non_interactive_func(char **str, char **av)
{
	char *cmd;
	pid_t pid;
	int status;
	int cmpt = 0;
	int i = 0;

	for (; str[cmpt]; cmpt++)
		;
	while (i < cmpt)
	{
		cmd = _strdup(str[i]);
		space(cmd);
		if (cmd[0] != '\0')
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(cmd, av, NULL) == -1)
					continue;
				else
					return (execve(cmd, av, NULL));
			}
			else
				wait(&status);
		}
		free(cmd);
		i++;
	}
	return (0);
}*/
