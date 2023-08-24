#include "shell.h"

/**
 * strcpy - copies a string pointr to
 * @des: the destination
 * @src: the source
 *
 * Return: pointer to the destination
 */
char *strcpy(char *des, char *src)
{
	int k = 0;

	if (des == src || src == 0)
		return (des);
	while (src[k])
	{
		des[i] = src[i];
		k++;
	}
	des[k] = 0;
	return (des);
}

/**
 * strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *strdup(const char *str)
{
	int len = 0;
	char *dst;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	for (len++; len--;)
		dst[len] = *--str;
	return (dst);
}

/**
 *puts - writes an input string
 *@str: string to be written
 *
 * Return: Nothing
 */
void puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes a character c to stdout
 * @c: Character to be written
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
