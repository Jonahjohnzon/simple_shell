#include <unistd.h>

/**
 * _putchar - writes the character c
 * @c: The character
 *
 */

void _putchar(char c)
{
	write(1, &c, 1);
}
