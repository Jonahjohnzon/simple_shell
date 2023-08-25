#include "shell.h"

/**
 * **strtow - breaks a string into words.
 * @str: string
 * @del: delimeter
 * Return: a pointer to a muster of strings, or NULL on non-success
 */

char **strtow(char *str, char *del)
{
	int i, j, k, m, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!del)
	{
		del = " ";
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], del) && (is_delim(str[i + 1], del) || !str[i + 1]))
			num_words++;
	}
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (is_delim(str[i], del))
			i++;
		k = 0;
		while (!is_delim(str[i + k], del) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **str_tow - breaks a string into words
 * @str: string
 * @del: delimeter
 * Return: a pointer to a muster of strings, or NULL on non-success
 */
char **str_tow(char *str, char del)
{
	int i, j, k, m, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != del && str[i + 1] == del) ||
		    (str[i] != del && !str[i + 1]) || str[i + 1] == del)
			num_words++;
	if (num_words == 0)
	{
		return (NULL);
	}
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (str[i] == del && str[i] != del)
			i++;
		k = 0;
		while (str[i + k] != del && str[i + k] && str[i + k] != del)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
