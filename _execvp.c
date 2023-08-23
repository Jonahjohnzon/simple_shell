#include "main.h"
/**
 * exe_now - execve
 * Description: execute
 * @c: input
 * @argv: input
 * Return: void
 */
void exe_now(char *c, char *const argv[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("fork");
	}
	else if (pid == 0)
	{
	execve(c, argv, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}
/**
 * _getenv - to get environment
 * Description: env get
 * @name: input
 * Return: String pointer
 */

char *_getenv(const char *name)
{
	int a, b;
	char *value;

	if (!name)
		return (NULL);
	for (a = 0; environ[a]; a++)
	{
	b = 0;
	if (name[b] == environ[a][b])
	{
	while (name[b])
	{
	if (name[b] != environ[a][b])
	{
	break;
	}
	b++;
	}
	if (name[b] == '\0')
	{
	value = (environ[a] + b + 1);
	return (value);
	}
	}
	}
	return (0);
}
/**
 * _execvp - execvp function
 * Description: execute Path
 * @file: input
 * @argv: input
 * Return: void
 */

void _execvp(const char *file, char *const argv[])
{
	if (access(argv[0], X_OK) == 0)
	{
		exe_now(argv[0], argv);
	}
	else
	{
	char *p = _getenv("PATH");

	if (p != NULL)
	{
	char *token = _stringtok(p, ":");

	while (token != NULL)
	{
		char path[1024];

		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, file);
		if (access(path, X_OK) == 0)
		{
			exe_now(path, argv);
			break;
		}
		token = _stringtok(NULL, ":");
	}
	}
	else
	{
	write(STDOUT_FILENO, "Command not found: ", 19);
	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, "\n", 1);
	}
	}
}
