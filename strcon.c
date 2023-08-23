#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space
 * @str: string
 * Return: pointer
 */

char *_strdup(char *str)
{
	int i, j;
	char *built;

	if (!str)
	{
		return (NULL);
	}
	for (j = 0; str[j] != '\0';)
	{
		j++;
	}
	built = malloc(sizeof(char) * j + 1);
	if (!built)
	{
		return (NULL);
	}
	for (i = 0; i < j; i++)
	{
		built[i] = str[i];
	}
	built[j] = str[j];
	return (built);
}

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @first: first string
 * @second: second string
 * @third: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *first, char *second, char *third)
{
	char *output;
	int l1, l2, l3, i, j;

	l1 = _strlen(first);
	l2 = _strlen(second);
	l3 = _strlen(third);

	output = malloc(l1 + l2 + l3 + 1);
	if (!output)
		return (NULL);

	for (i = 0; first[i]; i++)
		output[i] = first[i];
	j = i;

	for (i = 0; second[i]; i++)
		output[j + i] = second[i];
	j = j + i;

	for (i = 0; third[i]; i++)
		output[j + i] = third[i];
	j = j + i;

	output[j] = '\0';

	return (output);
}
