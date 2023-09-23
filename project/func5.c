#include "shell.h"

/**
 * init_ - starter
 * @cur: current token
 * @t: token
 */

void init_(char **cur, int t)
{
	pid_t p;

	if (t == EX_COM || t == P_COM)
	{
		p = fork();
		if (p == 0)
			executer(cur, t);
		else
		{
			waitpid(p, &la_statut, 0);
			la_statut >>= 8;
		}
	}
	else
		executer(cur, t);
}
