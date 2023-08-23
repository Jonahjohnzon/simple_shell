#include "shell.h"
/**
 * linkp - linkpath
 * @path: input
 * Return: pointer
 */
list_p *linkp(char *path)
{
	list_p *head = '\0';
	char *token;
	char *chpath = strdup(path);

	token = strtok(chpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _which - join
 * @file: input
 * @head: input
 * Return: char
 */
char *_which(char *file, list_p *head)
{
	struct stat st;
	char *str;

	list_p *tmp = head;

	while (tmp)
	{

		str = concat_all(tmp->dir, "/", file);
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		free(str);
		tmp = tmp->p;
	}

	return (NULL);
}

