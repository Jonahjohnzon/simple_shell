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
	if (result == -1)
	{
		perror("Error in getline");
		free(buffer);
		exit(EXIT_FAILURE);
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
 * main - main function
 * Description: this is where all functions come together
 * Return: 0 sucess
 */
int main(void)
{
	pid_t pid;

	int value;

	while (true)
	{
	_putchar('$');
	_putchar(' ');

	size_t n = 10;

	char *buffer = NULL;

	ssize_t result;

	char *tokens[200];

	char *argg;

	int n;

	result = getline(&buffer, &n, stdin);
	iffunction(tokens, result, buffer);
	pid = fork();

	if (pid < 0)
	{
		perror("Error with fork()");
	}
	if (pid == 0)
	{
		_execvp(tokens[0], tokens);
	}
	else
	{
	waitpid(pid, &n, 0);
	}
	free(buffer);
	}
	return (0);
}
