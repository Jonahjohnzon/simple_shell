#include "main.h"
/**
 * more_if - if
 * Description: if statement
 * @new_buffer: input
 * @p: input
 * @n: input
 * @line: input
 * Return: ssize_t
 */
void more_if(char *new_buffer, size_t p, size_t *n, char **line)
{
	size_t i;

	if (p >= *n - 1)
	{
	*n *= 2;
	new_buffer = (char *)malloc(*n);
	for (i = 0; i < p; ++i)
	{
	new_buffer[i] = (*line)[i];
	}
	free(*line);
	*line = new_buffer;
	}

}
/**
 * if_functions - if statement
 * Description: function that checks
 * @line: input
 * @n: input
 * Return: void
 */
ssize_t if_functions(char **line, size_t *n)
{
	static char buff[BUFFER_SIZE];

	static size_t b_p;

	static size_t b_s;

	size_t p = 0;

	int c;

	char *new_buffer = 0;

	while (true)
	{
	if (b_p >= b_s)
	{
	b_s = read(STDIN_FILENO, buff, BUFFER_SIZE);
	b_p = 0;
	if (b_s <= 0)
	{
	break;
	}
	}

	c = buff[b_p++];
	(*line)[p++] = (char)c;
	if (c == '\n')
	{
		break;
	}
	more_if(new_buffer, p, n, line);
	}
	(*line)[p] = '\0';
	if (p == 0 && b_s <= 0)
	{
	return (-1);
	}

	return ((ssize_t)p);
}

/**
 * _getline - getline function
 * Description: to get string fron shell
 * @line: input
 * @n: input
 * @stream: std
 * Return: ssize_t
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{

	if (line == NULL || stream == NULL || n == NULL)
	{
		return (-1);
	}
	if (*line == NULL || *n < BUFFER_SIZE)
	{
		*n = BUFFER_SIZE;
		*line = (char *)malloc(*n);
		if (*line == NULL)
		{
			return (-1);
		}
	}
		return (if_functions(line, n));
}
