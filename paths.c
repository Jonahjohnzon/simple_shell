/**
 * linkp - linkpath
 * @path: input
 * Return: pointer
 */
list_p *linkp(char *path)
{
	list_path *head = '\0';
	char *token;
	char *chpath = _strdup(path);

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
char *_which(char *file, list_path *head)
{
	struct stat st;
	char *str;
	]
	list_path *tmp = head;

	while (tmp)
	{

		str = _concat(tmp->dir, "/", file);
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		free(str);
		tmp = tmp->p;
	}

	return (NULL);
}

