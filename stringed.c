#include "shell.h"

/**
 * _strcpy - copies a string pointer from one to another
 * @des: destination
 * @src: source
 * Return: pointer to the destination
 */
char *_strcpy(char *des, char *src)
{
	int k = 0;

	if (des == src || src == 0)
		return (des);
	while (src[k])
	{
		des[k] = src[k];
		k++;
	}
	des[k] = 0;
	return (des);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *dst;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		len++;
	}
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
	{
		return (NULL);
	}
	for (len++; len--;)
	{
		dst[len] = *--str;
	}
	return (dst);
}

/**
 *_puts - writes an input string
 *@str: string to be written
 * Return: Nothing
 */
void _puts(char *str)
{
	int k = 0;

	if (!str)
	{
		return;
	}
	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
}

/**
 * _putchar - writes a character c to stdout
 * @c: Character to be written
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(1, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[k++] = c;
	}
	return (1);
}
