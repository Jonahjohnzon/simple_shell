#include "shell.h"

/**
 * _exitnow - exit
 * @arv: input
 */
void _exitnow(char **arvg)
{
	int i, n;

	if (arvg[1])
	{
		n = atoi(arvg[1]);
		if (n <= -1)
		{
			n = 2;
		}
		freearvg(arvg);
		exit(n);
	}
	for (i = 0; arvg[i]; i++)
		free(arvg[i]);
	free(arvg);
	exit(0);
}
/**
 * env - environment
 * @arv: array
 */
void env(char **arv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_print_word(environ[i]);
		_print_word("\n");
	}

}
