#include "shell.h"
/**
 * _unsetenv - deletes the variable name from an environment
 * @info: Structured arguments
 * @var: the environment variable string
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenv(info_table *info, char *var)
{
	list_table *node = info->envi;
	size_t a = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = _begin_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_change = delete_node_(&(info->envi), a);
			a = 0;
			node = info->envi;
			continue;
		}
		node = node->next;
		a++;
	}
	return (info->env_change);
}

/**
 * _setenv - add or modify the variable name with value to the environment
 * @info: Structured arguments.
 * @var: the environment variable string
 * @value: the environment variable value
 * Return: 0 on success
 */
int _setenv(info_table *info, char *var, char *value)
{
	char *buf = NULL;
	list_table *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->envi;
	while (node)
	{
		p = _begin_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_change = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_(&(info->envi), buf, 0);
	free(buf);
	info->env_change = 1;
	return (0);
}
