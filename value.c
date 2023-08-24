#include "shell.h"

/**
 * _chain - chain
 * @info: input
 * @buff: buffer
 * @p: current position
 * Return: int
 */
int _chain(info_table *info, char *buff, size_t *p)
{
	size_t j = *p;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;

		j++;

		info->cmd_buf_type = CMD_AND;
	}
	else if (buff[j] == ';')
	{
		buff[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*p = j;
	return (1);
}

/**
 * chek_chain - check chain
 * @info: input
 * @buff:  buffer
 * @p: buff address
 * @i: position buff
 * @len: length
 * Return: Void
 */
void chek_chain(info_table *info, char *buff, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * r_alias - replace alias
 * @info: input
 *
 * Return: int
 */
int r_alias(info_table *info)
{
	int i;
	list_table *nodes;
	char *p;

	for (i = 0; i < 10; i++)
	{
		nodes = node_starts_with(info->alias, info->argv[0], '=');
		if (!nodes)
		{
			return (0);
		}
		free(info->argv[0]);
		p = _strchr(nodes->str, '=');
		if (!p)
		{
			return (0);
		}
		p = _strdup(p + 1);
		if (!p)
		{
			return (0);
		}
		info->argv[0] = p;
	}
	return (1);
}
