#include "shell.h"

/**
 * space - 
 */
void space(char *s)
{
	int i = 0, j = 0;
	int l;

	l = strlen(s);
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
 * non_interactive - 
 */
int non_interactive_func(char **str, char **av)
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
		cmd = str[i];
		space(cmd);
		if (cmd[0] != '\0')
		{
			pid = fork();
			if (pid == 0)
			{
				execve(cmd, av, NULL);
				return (1);
			}
			else if (pid < 0)
			{
				perror("fork");
				return (0);
			}
			else
				wait(&status);
		}
		i++;
	}
	return (0);
}
