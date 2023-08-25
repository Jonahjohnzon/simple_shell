#include "shell.h"

/**
 *_errputs - displays a given string
 * @str: string to be written
 *
 * Return: Nothing
 */
void _errputs(char *str)
{
	int a = 0;

	if (!str)
	{
		return;
	}
	while (str[a] != '\0')
	{
		_errputchar(str[a]);
		a++;
	}
}

/**
 * _errputchar - list the specified character by the argument to stderr
 * @c: character to be written
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _errputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[a++] = c;
	}
	return (1);
}

/**
 * _putfdr - register character c to given file dscriptor
 * @c: character to be written
 * @fdr: file descriptor to be processed
 * Return: input
 */
int _putfdr(char c, int fdr)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fdr, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[a++] = c;
	}
	return (1);
}

/**
 *_putsfdr - register a given string
 * @str: the string to be printed
 * @fdr: filedescriptor to be processed
 * Return: number of display char
 */
int _putsfdr(char *str, int fdr)
{
	int a = 0;

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		a += _putfdr(*str++, fdr);
	}
	return (a);
}
