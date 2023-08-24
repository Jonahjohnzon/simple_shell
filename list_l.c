#include "shell.h"

/**
 * list_l - linked list
 * @h: input
 * Return: size_t
 */
size_t list_l(const list_table *h)
{
	size_t value = 0;

	while (h)
	{
		h = h->next;
		value++;
	}
	return (value);
}

/**
 * list_to_strings - an array of string
 * @head: input
 * Return: array
 */
char **list_to_strings(list_table *heads)
{
	list_table *nodes = heads;
	size_t i = list_l(heads), j;
	char **strs;
	char *str;

	if (!heads || !i)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
	{
		return (NULL);
	}
	for (i = 0; nodes; nodes = nodes->next, i++)
	{
		str = malloc(_strlen(nodes->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, nodes->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}
