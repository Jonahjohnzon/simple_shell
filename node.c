#include "shell.h"
/**
 * add_node_end - adds a new node
 * @head: input
 * @str: input
 * Return: list_p
 */
list_p *add_node_end(list_p **head, char *str)
{

	list_p *t;
	list_p *n;

	n = malloc(sizeof(list_p));
	if (!n || !str)
	{
		return (NULL);
	}
	n->dir = str;

	n->p = '\0';
	if (!*head)
	{
		*head = n;
	}
	else
	{
		t = *head;

		while (t->p)
		{

			t = t->p;
		}
		t->p = n;
	}

	return (*head);
}

