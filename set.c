#include "shell.h"
/**
 * _seten - setenv
 * @inform: input
 * Return: int
 */
int _seten(info_table *inform)
{
	if (inform->argcs != 3)
	{
		_errputs("Incorrect number of arguements\n");

		return (1);
	}
	if (_setenv(inform, inform->argvv[1], inform->argvv[2]))
	{
		return (0);
	}
	return (1);
}

/**
 * _unseten - unseten
 * @inform: input
 * Return: int
 */
int _unseten(info_table *inform)
{
	int i;

	if (inform->argcs == 1)
	{
		_errputs("Too few arguements.\n");

		return (1);
	}
	for (i = 1; i <= inform->argcs; i++)
		_unsetenv(inform, inform->argvv[i]);

	return (0);
}
