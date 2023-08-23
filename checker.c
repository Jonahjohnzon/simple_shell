#include "shell.h"

/**
* _checkers - check
* @arv: input
* Return: void
*/
void(*_checkers(char **arvg))(char **arvg)
{
	int a, b;

	_build T[] = {
		{"exit", exitt},
		{"env", env}
	};

	for (i = 0; T[i].name; a++)
	{
		b = 0;
		if (T[a].name[b] == arvg[0][b])
		{
		for (b = 0; arvg[0][b]; b++)
		{
			if (T[a].name[b] != arvg[0][b])
			{
				break;
			}
		}
		if (!arvg[0][b])
		{
			return (T[a].func);
		}
		}
	}
	return (0);
}
