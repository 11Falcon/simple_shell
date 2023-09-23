#include "shell.h"

/**
 * non_inter - non interactive
 */

void non_inter(void)
{
	char **cur = NULL;
	int i, stat, t = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&lin, &n, stdin) != -1)
		{
			sup_n_line(lin);
			comment(lin);
			comm_ = toking(lin, ";");
			for (i = 0; comm_[i] != NULL; i++)
			{
				cur = toking(comm_[i], " ");
				if (cur[0] == NULL)
				{
					free(cur);
					break;
				}
				t = par(cur[0]);
				init_(cur, t);
				free(cur);
			}
			free(comm_);
		}
		free(lin);
		exit(stat);
	}
}
