#include "shell.h"
/**
 * _strlen - calculate the length of a string
 * @str: string
 * Return: the length of string
 */
int *_strlen(char *str)
{
	int j = 0;

	while (*(str + j) != '\0')
	{
		j++;
	}
	return (j);
}
