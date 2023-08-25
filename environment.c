#include "shell.h"

/**
 * _env - current env
 * @info: input
 * Return:  0
 */
int _env(info_table *info)
{
	print_list_s(info->envi);

	return (0);
}

/**
 * _getenv - gets env
 * @info: info
 * @name: input
 * Return: 0
 */
char *_getenv(info_table *info, const char *name)
{
	list_table *nodes = info->envi;

	char *p;

	while (nodes)
	{
		p = _begin_with(nodes->str, name);
		if (p && *p)
		{
			return (p);
		}
		nodes = nodes->next;
	}
	return (NULL);
}

