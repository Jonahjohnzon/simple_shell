#include "shell.h"

/**
 * _free - deallocates the memory peviously allocated
 * @loc: pointer to a memory allocated to b deallocated
 *
 * Return: 1 if freed, otherwise 0.
 */
int _free(void **loc)
{
	if (loc && *loc)
	{
		free(*loc);
		*loc = NULL;
		return (1);
	}
	return (0);
}
