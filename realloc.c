#include "shell.h"
/**
 * _realloc - realloc
 * @p: input
 * @o_s: old size
 * @n_s: new size
 */
void **_realloc(char *p, unsigned int o_s, unsigned int n_s)
{
	void **ptr;

	if (p == NULL) {
		ptr = malloc(n_s);
		if (ptr == NULL)
			return NULL;
		return ptr;
	}
	if (n_s == 0)
	{
		free(p);
		return NULL;
	}
	if (n_s == o_s)
		return (void **)p;
	ptr = malloc(n_s);
	if (ptr == NULL)
		return NULL;
	if (o_s > n_s)
		o_s = n_s;
/**	while (o_s--)
*		ptr[o_s] = p[o_s];
*	free(p);
*/	
	return ptr;
}
