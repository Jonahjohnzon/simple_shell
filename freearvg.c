#include "shell.c"
/**
 * freearvg - frees
 *@arvg: pointers
 */

void freearvg(char **arvg)
{
	int i;

	for (i = 0; arvg[i]; i++)
		free(arvg[i]);
	free(arvg);
}
