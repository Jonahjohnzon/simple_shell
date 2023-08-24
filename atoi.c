#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @dets: address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *dets)
{
	return (isatty(STDIN_FILENO) && dets->readfd <= 2);
}

/**
 * is_delim - inspect if character is a delimeter
 * @c: character to search
 * @del: delimeter
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - inspect for alphabetic character
 *@c: character to insert
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@str: the string representation of an integral number
 *Return: 0 if no valid conversion on string, converted number otherwise
 */

int _atoi(char *str)
{
	int i, sign = 1, flag = 0, value;
	unsigned int outcome = 0;

	for (i = 0;  str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			outcome *= 10;
			outcome += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		value = -outcome;
	else
		value = outcome;

	return (value);
}

