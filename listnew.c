#include "shell.h"

/**
 * _addnode - node add
 * @heads: input
 * @st: input
 * @num: input
 * Return: list_table
 */
list_table *_addnode(list_table **heads, const char *st, int num)
{
	list_table *new_head;

	if (!heads)
	{
		return (NULL);
	}
	new_head = malloc(sizeof(list_table));
	if (!new_head)
	{
		return (NULL);
	}
	_memset((void *)new_head, 0, sizeof(list_table));
	new_head->num = num;
	if (st)
	{
		new_head->str = _strdup(st);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *heads;
	*heads = new_head;
	return (new_head);
}

/**
 * add_node_ - add node
 * @heads: input
 * @st: string
 * @num: input
 * Return: list_table
 */
list_table *add_node_(list_table **heads, const char *st, int num)
{
	list_table *new_node, *node;

	if (!heads)
	{
		return (NULL);
	}
	node = *heads;
	new_node = malloc(sizeof(list_table));
	if (!new_node)
	{
		return (NULL);
	}
	_memset((void *)new_node, 0, sizeof(list_table));
	new_node->num = num;
	if (st)
	{
		new_node->str = _strdup(st);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*heads = new_node;
	return (new_node);
}

/**
 * print_list_s - print string elrment
 * @v: input
 * Return: size_t
 */
size_t print_list_s(const list_table *v)
{
	size_t i = 0;

	while (v)
	{
		_puts(v->str ? v->str : "(nil)");
		_puts("\n");
		v = v->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_ - delete
 * @head: input
 * @ind: input
 * Return: int
 */
int delete_node_(list_table **head, unsigned int ind)
{
	list_table *node, *prev_node;

	unsigned int i = 0;

	if (!head || !*head)
	{
		return (0);
	}

	if (!ind)
	{
		node = *head;
		*head = (*head)->next;

		free(node->str);

		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == ind)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - free node
 * @head_: address
 *
 * Return: void
 */
void free_list(list_table **head_)
{
	list_table *nodes, *next_nodes, *head;

	if (!head_ || !*head_)
	{
		return;
	}
	head = *head_;
	nodes = head;
	while (nodes)
	{
		next_nodes = nodes->next;
		free(nodes->str);
		free(nodes);
		nodes = next_nodes;
	}
	*head_ = NULL;
}
