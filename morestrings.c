#include "shell.h"

/**
 **_strncpy - copies up to n characters from the string pointer to
 *@des: pointer destination
 *@src: string source
 *@n: required number of characters copied
 *Return: pointer to copied string
 */
char *_strncpy(char *des, char *src, int n)
{
	int a, b;
	char *str = des;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		des[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			des[b] = '\0';
			b++;
		}
	}
	return (str);
}

/**
 **_strncat - appends two strings
 *@str1: pointer destination
 *@str2: string to be appended
 *@b: maximum amount of character to be appended
 *Return: pointer to derived string dstination
 */
char *_strncat(char *str1, char *str2, int b)
{
	int m, n;
	char *s = str1;

	m = 0;
	n = 0;
	while (str1[m] != '\0')
	{
		m++;
	}
	while (str2[n] != '\0' && n < b)
	{
		str1[m] = str2[n];
		m++;
		n++;
	}
	if (n < b)
	{
		str1[m] = '\0';
	}
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@str: parsed string
 *@c: awaiting character
 *Return: pointer to string memory
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
		{
			return (str);
		}
	} while (*str++ != '\0');

	return (NULL);
}
