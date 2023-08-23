#include "shell.h"


/**
 * _strtok - breaks a string into a series of tokens using delimiter
 * @str: content of the string
 * @delim: the delimiter
 * Return: muster of pointers
 */

char **_strtok(char *str, const char *delim)
{
	int i, j;
	char **muster;
	char *token;
	char *dupl;

	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
	{
		perror(_getenv("_"));
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		dupl[i] = str[i];
		i++;
	}
	dupl[i] = '\0';

	token = strtok(dupl, delim);
	muster = malloc((sizeof(char *) * 2));
	muster[0] = _strdup(token);

	i = 1;
	j = 3;
	while (token)
	{
		token = strtok(NULL, delim);
		muster = _realloc(muster, (sizeof(char *) * (j - 1)), (sizeof(char *) * j));
		muster[i] = _strdup(token);
		i++;
		j++;
	}
	free(dupl);
	return (muster);
}

/**
 * _realloc - Reallocates memory block
 * @ind: former pointer
 * @past_size: past size of former pointer
 * @built_size: built size for our pointer
 * Return: Built resized pointer
 */

void *_realloc(void *ind, unsigned int past_size, unsigned int built_size)
{
	char *built;
	char *past;

	unsigned int i;

	if (ind == NULL)
	{
		return (malloc(built_size));
	}
	if (built_size == past_size)
	{
		return (ind);
	}
	if (built_size == 0 && ind != NULL)
	{
		free(ind);
		return (NULL);
	}
	built = malloc(built_size);
	past = ind;
	if (built == NULL)
		return (NULL);

	if (built_size > past_size)
	{
		for (i = 0; i < past_size; i++)
			built[i] = past[i];
		free(ind);
		for (i = past_size; i < built_size; i++)
			built[i] = '\0';
	}
	if (built_size < past_size)
	{
		for (i = 0; i < built_size; i++)
			built[i] = past[i];
		free(ind);
	}
	return (built);
}

