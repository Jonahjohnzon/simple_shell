#include "shell.h"

/**
 * input_buff - buffer
 * @info: input
 * @buff: input
 * @len: input
 *
 * Return: ssize
 */
ssize_t input_buff(info_table *info, char **buff, size_t *len)
{
	ssize_t r = 0;
	size_t len_ = 0;

	if (!*len)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, ctrl_Handler);
#if USE_GETLINE
		r = getline(buff, &len_, stdin);
#else
		r = _getline(info, buff, &len_);
#endif
		if (r > 0)
		{
			if ((*buff)[r - 1] == '\n')
			{
				(*buff)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comment(*buff);
			build_event_list(info, *buff, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buff;
			}
		}
	}
	return (r);
}

/**
 * _input - input
 * @info: inp
 *
 * Return: ssize
 */
ssize_t _input(info_table *info)
{
	static char *buff;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buff_ = &(info->arg), *p;

	_putchar(BUF_FLUSH);

	r = input_buff(info, &buff, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buff + i;

		chek_chain(info, buff, &j, i, len);
		while (j < len)
		{
			if (_chain(info, buff, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_ = p;
		return (_strlen(p));
	}

	*buff_ = buff;
	return (r);
}

/**
 * read_buff - buffer
 * @info: info_t
 * @buff: buff
 * @i: input
 *
 * Return: ssize
 */
ssize_t read_buff(info_table *info, char *buff, size_t *i)
{
	ssize_t value = 0;

	if (*i)
		return (0);
	value = read(info->readfd, buff, READ_BUF_SIZE);
	if (value >= 0)
		*i = value;
	return (value);
}

/**
 * _getline - getlin from terminal
 * @inform: info
 * @pt: info
 * @leng: input
 * Return: int
 */
int _getline(info_table *inform, char **pt, size_t *leng)
{
	static char buff[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pt;
	if (p && leng)
		s = *leng;
	if (i == len)
		i = len = 0;

	r = read_buff(inform, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buff + i, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buff + i, k - i);
	else
		_strncpy(new_p, buff + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (leng)
		*leng = s;
	*pt = p;
	return (s);
}

/**
 * ctrl_Handler - ctrl-C
 * @sig: input
 *
 * Return: void
 */
void ctrl_Handler(__attribute__((unused))int sig)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
