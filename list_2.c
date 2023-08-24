#include "main.h"
**
 * print_list - printf
 * @h: input
 * Return: size of list
 */
size_t print_list(const list_table *value)
{
	size_t i = 0;

	while (value)
	{
		_puts(convert_number(value->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(value->str ? value->str : "(nil)");
		_puts("\n");
		value = value->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - return node
 * @node: input
 * @pre: input
 * @c: input
 * Return: list
 */
list_table *node_starts_with(list_table *nodes, char *pre, char c)
{
	char *p = NULL;

	while (nodes)
	{
		p = starts_with(nodes->str, pre);
		if (p && ((c == -1) || (*p == c)))
		{
			return (nodes);
		}
		nodes = nodes->next;
	}
	return (NULL);
}

/**
 * get_node_index - index  node
 * @head: head
 * @nodes: head
 * Return: ssize
 */
ssize_t get_node_index(list_table *head, list_table *nodes)
{
	size_t i = 0;

	while (head)
	{
		if (head == nodes)
		{
			return (i);
		}
		head = head->next;

		i++;
	}
	return (-1);
}
