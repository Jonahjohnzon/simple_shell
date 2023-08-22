#include "main.h"
/**
 * _strc - locates a character in a string
 * @st: string
 * @c: character
 * Return: 0
 */
int _strc(const char *st, char c)
{
	while (*st != '\0')
	{
		if (*st == c)
		{
			return (1);
		}
		++st;
	}
	return (0);
}

/**
 * _stringtok - break string into tokens using delimiter
 * @st: string
 * @delim: delimiter
 * Return: the token
 */
char *_stringtok(char *st, const char *delim)
{
	static char *last;

	char *token;

	if (st != NULL)
	{
		last = st;
	}
	else
	{
		if (last == NULL)
			return (NULL);
		st = last;
	}
	while (*st != '\0' && _strc(delim, *st))
	{
		++st;
	}
	if (*st == '\0')
	{
		last = NULL;
		return (NULL);
	}
	token = st;
	while (*st != '\0' && !_strc(delim, *st))
	{
		++st;
	}
	if (*st != '\0')
	{
		*st = '\0';
		last = st + 1;
	}
	else
	{
		last = NULL;
	}
	return (token);
}
