#include "shell.h"

/**
 * get_envi - getenv
 * @inform: input
 * Return: 0
 */
char **get_envi(info_table *inform)
{
	if (!inform->enviro || inform->env_change)
	{
		inform->enviro = list_to_strings(inform->envi);
		inform->env_change = 0;
	}

	return (inform->enviro);
}
