#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_word - prints a string
 * @str: string to print
 */

void _print_word(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
