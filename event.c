#include "shell.h"

/**
 * get_history_file - collects the event folder
 * @info: structured parameter
 *
 * Return: event folder string allocated
 */

char *get_history_file(info_table *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - writes or appends to an existing folder
 * @info: structured parameter
 *
 * Return: 1 on success, else -1
 */
int write_history_event(info_table *info)
{
	ssize_t fdr;
	char *foldername = get_history_file(info);
	list_t *node = NULL;

	if (!foldername)
		return (-1);

	fdr = open(foldername, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(foldername);
	if (fdr == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfdr(node->str, fdr);
		_putfdr('\n', fdr);
	}
	_putfdr(BUF_FLUSH, fdr);
	close(fdr);
	return (1);
}

/**
 * read_event - reads event from file
 * @info: structured parameter
 *
 * Return: histcount on success, 0 otherwise
 */
int read_event(info_table *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_event_list - adds entry to event linked list
 * @info: structured potential arguments
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_event_list(info_table *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_event - renumbers the event linked list
 * @info: Structured potential arguments.
 *
 * Return: created histcount
 */
int renumber_event(info_table *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
