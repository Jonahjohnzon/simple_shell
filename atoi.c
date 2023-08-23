#include "shell.h"
/**
 * _atoi - converts a string into an integer
 *@str: string represntation
 *Return: int
 */
int _atoi(char *str)
{
	int i, j, k;

	k = 1;
	i = 0;
	j = 0;

	while (!((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			k = k * (-1);
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		j = (j * 10) + (k * (str[i] - '0'));
		i++;
	}
	return (i);
}
