#include "shell.h"

/**
 * interactive - reinstate true when shell is interactive mode
 * @dets: content label
 *
 * Return: 1 when interactive mode, 0 instead
 */
int interactive(info_table *dets)
{
	return (isatty(STDIN_FILENO) && dets->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: character to search
 * @del: delimeter string
 * Return: 1 when true, 0 when false
 */
int is_delim(char c, char *del)
{
	while (*del)
	{
		if (*del++ == c)
		{
			return (1);
		}
	}
	return (0);
}

/**
 *_isalpha - inspect for alphabetic character
 *@c: character to be coded
 *Return: 1 if c is alphabetic, 0 instead
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 *_atoi - converts a string into an integer
 *@str: string
 *Return: 0 if no value conversion, converted integral number instead
 */

int _atoi(char *str)
{
	int i;
	int j = 1;
	int k = 0, value;
	unsigned int outcome = 0;

	for (i = 0;  str[i] != '\0' && k != 2; i++)
	{
		if (str[i] == '-')
		{
			j *= -1;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			k = 1;
			outcome *= 10;
			outcome += (str[i] - '0');
		}
		else if (k == 1)
			k = 2;
	}

	if (j == -1)
	{
		value = -outcome;
	}
	else
	{
		value = outcome;
	}

	return (value);
}

