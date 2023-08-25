#include "shell.h"

/**
 * _cmd - exec or not
 * @info: input
 * @location: path
 * Return: int
 */
int _cmd(info_table *info, char *location)
{
	struct stat st;

	(void)info;
	if (!location || stat(location, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * _dup - duplicate
 * @path: PATH
 * @a: starting
 * @b: stopping
 * Return: pointer
 */
char *_dup(char *path, int a, int b)
{
	static char buff[1024];
	int i = 0, k = 0;

	for (k = 0, i = a; i < b; i++)
		if (path[i] != ':')
		{
			buff[k++] = path[i];
		}
	buff[k] = 0;
	return (buff);
}

/**
 * _path - PATH string
 * @info: info
 * @paths: input
 * @cmd: the cmd
 * Return: pointer
 */
char *_path(info_table *info, char *paths, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!paths)
		return (NULL);
	if ((_strlen(cmd) > 2) && _begin_with(cmd, "./"))
	{
		if (_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!paths[i] || paths[i] == ':')
		{
			path = _dup(paths, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (_cmd(info, path))
			{
				return (path);
			}
			if (!paths[i])
			{
				break;
			}
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
