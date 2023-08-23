#include "main.h"
/**
 * _atoi - convert string to integer
 * @str: string
 *
 * Return: int
 */
int _atoi(const char *str)
{
	int a = 0;

	int b = 1;

	int i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		b = (str[i++] == '-') ? -1 : 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (b * a);
}
