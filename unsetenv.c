#include "shell.h"
/**
 * _unset - Removeenv
 * @arvg: input
 */
void _unset(char **arvg)
{
	int ia, je;

	if (!arvg[1])
	{
		perror(_getenv("_"));
		return;
	}
	for (ia = 0; environ[ia]; ia++)
	{
		je = 0;
		if (arvg[1][je] == environ[ia][je])
		{
		while (arvg[1][je])
		{
			if (arvg[1][je] != environ[ia][je])
				break;

			je++;
			}
			if (arvg[1][je] == '\0')
			{
				free(environ[ia]);
				environ[ia] = environ[ia + 1];
				while (environ[ia])
				{
					environ[ia] = environ[ia + 1];
					ia++;
				}
				return;
			}
		}
	}
}
