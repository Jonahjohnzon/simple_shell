#include "main.h"

/**
 * _strcmp - strcmp function
 * Description: to compare two strings
 * @st1: input
 * @st2: input
 * Return: int
 */

int _strcmp(const char *st1, const char *st2)
{
	while (*st1 != '\0' && *st2 != '\0')
	{
		if (*st1 != *st2)
		{
			return (*st1 - *st2);
		}
		st1++;
		st2++;
	}
	return (*st1 - *st2);
}
/**
 * iffunction - hold my if statements
 * Description: if statements
 * @tokens: input
 * @result: input
 * @buffer: input
 * Return: void
 */
void iffunction(char **tokens, ssize_t result, char *buffer)
{	
	(void)buffer;
	if (result == -1)
	{
		if (isatty(STDIN_FILENO))
		{
		_putchar('\n');
		free(buffer);
		}
		exit(0);
	}
	if (buffer[result - 1] == '\n')
	{
		buffer[result - 1] = '\0';
	}
	if (_strcmp(buffer, "exit") == 0)
	{
		exit(0);
	}
	if (_strcmp(buffer, "env") == 0)
	{
		print_environment();
	}
	_strtok(buffer, tokens);
}
/**
 * _exec - execve
 * Description: exec
 * Return: void
 */
void _exec(void)
{
	size_t n = 10;

	char *buffer = NULL;

	ssize_t result;

	char *tokens[200];

	result = _getline(&buffer, &n, stdin);
	iffunction(tokens, result, buffer);
	_execvp(tokens[0], tokens);
	free(buffer);
}
/**
 * checck - checker
 * @sn: input
 */
void checck(int sn)
	{
	if (sn == SIGINT)
	{
	write(1, "\n#cisfun$ ", 11);
	}
}
/**
 * main - main function
 * Description: this is where all functions come together
 * Return: 0 sucess
 */
int main(void)
{	

	signal(SIGINT, checck);
	while (1)
	{
	if (isatty(STDIN_FILENO))
	{
	write(1, "#cisfun$ ", 9);
	}
	_exec();
	}

	return (0);
}
