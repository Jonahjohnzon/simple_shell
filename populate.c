#include "shell.h"
/**
 * env_list - env populate
 * @inform: input
 * Return: Always 0
 */
int env_list(info_table *inform)
{
	list_table *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
	{
		add_node_(&node, environ[i], 0);
	}
	inform->env = node;
	return (0);
}
