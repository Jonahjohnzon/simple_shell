#include "shell.h"

/**
 **_memset - copies the value into each first n character pointer to
 *@str: pointer to the memory block to fill
 *@b: the byte to be set
 *@n: number of bytes to be set
 *Return: pointer to the memory block str (s)
 */
char *_memset(char *str, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = b;
	return (s);
}

/**
 * ffree - frees a substring
 * @ss: substring
 */
void ffree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _realloc - resize a block of memory pointed by previously allocated ptr
 * @ptr: pointer to previous memory block to be reallocated
 * @past_size: past block byte size
 * @built_size: built block byte size
 *
 * Return: pointer to the built allocated memory.
 */
void *_realloc(void *ptr, unsigned int past_size, unsigned int built_size)
{
	char *p;

	if (!ptr)
		return (malloc(built_size));
	if (!built_size)
		return (free(ptr), NULL);
	if (built_size == past_size)
		return (ptr);

	p = malloc(built_size);
	if (!p)
		return (NULL);

	past_size = past_size < built_size ? past_size : built_size;
	while (past_size--)
		p[past_size] = ((char *)ptr)[past_size];
	free(ptr);
	return (p);
}
