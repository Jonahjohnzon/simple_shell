#include "shell.h"

/**
 * _strlen - calculate the length of a string
 * @str: string
 *
 * Return: integer
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * _strcmp - comparison of two strings.
 * @str1: first string
 * @str2: second string
 *
 * Return: int
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}

/**
 * _begin_with - checks if a string begin with another string
 * @str_a: string to search
 * @str_b: substring to find
 *
 * Return: next char of str_a or NULL
 */
char *_begin_with(const char *str_a, const char *str_b)
{
	while (*str_b)
		if (*str_b++ != *str_a++)
			return (NULL);
	return ((char *)str_a);
}

/**
 * _strcat - concatenates two strings
 * @des: destination
 * @src: source
 *
 * Return: pointer
 */
char *_strcat(char *des, char *src)
{
	char *ptr = des;

	while (*des)
		des++;
	while (*src)
		*des++ = *src++;
	*des = *src;
	return (ptr);
}
