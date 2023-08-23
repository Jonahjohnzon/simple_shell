#include "shell.h"
/**
 * _getenv - get path
 * @name: input
 * Return: char
 */
char *_getenv(const char *name)
{
	int a, b;
	char *value;

	if (!name)
	{
		return (NULL);
	}
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (name[b] == environ[a][b])
		{
			while (name[b])
			{
			if (name[b] != environ[a][b])
			{
			break;
			}

				b++;
			}
			if (name[b] == '\0')
			{
				value = (environ[a] + b + 1);
				return (value);
			}
		}
	}
	return (0);
}

