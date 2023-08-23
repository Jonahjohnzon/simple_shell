#include "shell.h"

/**
* _checkers - check
* @arvg: input
* Return: void
*/
void(*_checkers(char **arvg))(char **arvg)
{
	int a, b;

	_build T[] = {
		{"exit", _exitnow},
		{"env", env},
		{NULL, NULL}
	};

	for (a = 0; T[b].name; a++)
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
