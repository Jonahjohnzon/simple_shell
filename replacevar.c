#include "shell.h"
/**
 * r_vars - var replace
 * @info: input
 * Return:int
 */
int r_vars(info_table *info)
{
	int i = 0;
	list_table *nodes;

	for (i = 0; info->argvv[i]; i++)
	{
		if (info->argvv[i][0] != '$' || !info->argvv[i][1])
		{
			continue;
		}

		if (!_strcmp(info->argvv[i], "$?"))
		{
			r_string(&(info->argvv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argvv[i], "$$"))
		{
			r_string(&(info->argvv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		nodes = node_starts_with(info->envi, &info->argvv[i][1], '=');
		if (nodes)
		{
			r_string(&(info->argvv[i]),
				_strdup(_strchr(nodes->str, '=') + 1));

			continue;
		}
		r_string(&info->argvv[i], _strdup(""));

	}
	return (0);
}

/**
 * r_string - replace string
 * @o: input
 * @n: input
 * Return: 0
 */
int r_string(char **o, char *n)
{
	free(*o);
	*o = n;
	return (1);
}
