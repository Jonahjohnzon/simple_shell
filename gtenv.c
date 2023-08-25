#include "shell.h"

/**
 * get_envi - getenv
 * @inform: input
 * Return: 0
 */
char **get_envi(info_table *inform)
{
	if (!inform->environ || inform->env_changed)
	{
		inform->environ = list_to_strings(inform->env);
		inform->env_changed = 0;
	}

	return (inform->environ);
}
