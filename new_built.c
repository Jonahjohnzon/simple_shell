#include "shell.h"

/**
 * _myhistory - displays the history list from 0.
 * @info: Structured arguments
 * Return: Always 0
 */
int _myhistory(info_table *info)
{
	print_list(info->historys);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: structured arguments
 * @str: string
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_table *info, char *str)
{
	char *p, a;
	int outcome;

	p = _strchr(str, '=');
	if (!p)
	{
		return (1);
	}
	a = *p;
	*p = 0;
	outcome = delete_node_(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = a;
	return (outcome);
}

/**
 * set_alias - assign string with alias
 * @info: structured arguments
 * @str: string
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_table *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
	{
		return (1);
	}
	if (!*++p)
	{
		return (unset_alias(info, str));
	}
	unset_alias(info, str);
	return (add_node_(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - display the string alias
 * @node: node attached to the alias
 *
 * Return: 0 on success, 1 on error
 */
int print_alias(list_table *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		{
			_putchar(*a);
		}
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structured arguments
 *  Return: Always 0
 */
int _myalias(info_table *info)
{
	int a = 0;
	char *p = NULL;
	list_table *node = NULL;

	if (info->argcs == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argvv[a]; a++)
	{
		p = _strchr(info->argvv[a], '=');
		if (p)
			set_alias(info, info->argvv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argvv[a], '='));
	}

	return (0);
}
