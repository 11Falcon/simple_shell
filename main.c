#include "shell.h"

/**
 * main - the main function
 * @argc: the counter
 * @argv: array of argc
 * Return: stat
 */
int main(int argc, char **argv)
{
	char **cmd = NULL;
	int k = 0, t;
	size_t a = 0;

	signal(SIGINT, ctl_c_);
	_name = argv[0];
	while (1)
	{
		non_inter();
		_write_("($) ", STDOUT_FILENO);
		if (getline(&lin, &a, stdin) == -1)
		{
			free(lin);
			exit(stat);
		}
		sup_n_line(lin);
		comment(lin);
		comm_ = toking(lin, ";");
		while (comm_[k] != NULL)
		{
			cmd = toking(comm_[i], " ");
			if (cmd[0] = NULL)
			{
				free(cmd);
				break;
			}
			t = par(cmd[0]);
			init_(cmd, t);
			free(cmd);
			k++;
		}
		free(comm_);
	}
	free(lin);
	return (stat);
	(void)argc;
}
