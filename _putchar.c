#include <unistd.h>

/**
 * _putchar - writes the character c
 * @c: The character
 *
 * Return: 0
 */

void _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
