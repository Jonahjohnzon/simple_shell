#include <stdio.h>
#include "main.h"
/**
 * _getenv - to get environment
 * Description: env get
 * @name: input
 * Return: String pointer
 */

char *_getenv(char *name)
{	char environment =
		"PATH=/usr/bin:/bin\n"
		"HOME=/home/user\n"
		"USER=user\n";

	char *pt = environment;

	while (*pt != '\0')
	{
		char *env_var = pt;

		char *name_p = name;

		while (*name_p != '\0' && *env_var == *name_p)
		{
			env_var++;
			name_p++;
		}
		if (*env_var == '=' && *name_p == '\0')
		{
			return (env_var + 1);
		}
		while (*pt != '\0' && *pt != '\n')
		{
			p++;
		}
		if (*pt == '\n')
		{
			p++;
		}
	}
	return (NULL);
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
	char *p = _getenv("PATH");

	char *token = strtok(p, ":");

	while (token != NULL)
	{
		char path[1024];

		int stt;

		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, file);
		if (access(path, X_OK) == 0)
		{
			pid_t pid = fork()

				if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					execve(path, argv, NULL);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
				{
					waitpid(pid, &stt, 0);
					exit(0);
					return;
				}
		}
		token = strtok(NULL, ":");
		exit(0);

	}
	exit(EXIT_FAILURE);
}
