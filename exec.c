#include "shell.h"

/**
 * _exec - executes a command
 * @argv: input
 */

void _exec(char **argv)
{

	int value, state;

	if (!argv || !argv[0])
		return;
	value = fork();
	if (value == -1)
	{
		perror(_getenv("_"));
	}
	if (value == 0)
	{
		execve(argv[0], argv, environ);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&state);
}
