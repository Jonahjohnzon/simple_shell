#include "shell.h"

/**
 * _app - main shell
 * @inform: input
 * @a: input
 *
 * Return: 0 on success, 1 on error, or error code
 */
int _app(info_table *inform, char **a)
{
	ssize_t r = 0;
	int built_ret = 0;

	while (r != -1 && built_ret != -2)
	{
		clear_info(inform);
		if (interactive(inform))
		{
			_puts("$ ");
		}
		_errputchar(BUF_FLUSH);
		r = _input(inform);
		if (r != -1)
		{
			set_info(inform, a);
			built_ret = find_builtin(inform);
			if (built_ret == -1)
				find_cmd(inform);
		}
		else if (interactive(inform))
			_putchar('\n');
		free_info(inform, 0);
	}
	write_history(inform);
	free_info(inform, 1);
	if (!interactive(inform) && inform->status)
		exit(inform->status);
	if (built_ret == -2)
	{
		if (inform->err_num == -1)
		{
			exit(inform->status);
		}


		exit(inform->err_num);
	}
	return (built_ret);
}

/**
 * find_built - built cmd
 * @inform: input
 * Return: int
 */
int find_built(info_table *inform)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _exit},
		{"env", _myenv},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(inform->argv[0], builtintbl[i].type) == 0)
		{
			inform->line_count++;
			built_in_ret = builtintbl[i].func(inform);
			break;
		}
	return (built_in_ret);
}

/**
 * find_c - find command
 * @inform: input
 */
void find_c(info_table *inform)
{
	char *pathe = NULL;
	
	int i, k;

	inform->path = inform->argv[0];
	if (inform->linecount_flag == 1)
	{
		inform->line_count++;
		inform->linecount_flag = 0;
	}
	for (i = 0, k = 0; inform->arg[i]; i++)
		if (!is_delim(inform->arg[i], " \t\n"))
			k++;
	if (!k)
	{
		return;
	}

	pathe = find_path(inform, _getenv(inform, "PATH="), inform->argv[0]);
	if (pathe)
	{
		inform->path = pathe;
		fork_c(info);
	}
	else
	{
		if ((interactive(inform) || _getenv(inform, "PATH=")
			|| inform->argv[0][0] == '/') && _cmd(info, inform->argv[0]))
			fork_c(inform);
		else if (*(inform->arg) != '\n')
		{
			inform->status = 127;
			print_error(inform, "not found\n");
		}
	}
}

/**
 * fork_c - fork cmd
 * @info: input
 * Return: void
 */
void fork_c(info_table *inform)
{
	pid_t _pid;

	_pid = fork();
	if (_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (_pid == 0)
	{
		if (execve(inform->path, inform->argv, get_environ(inform)) == -1)
		{
			free_info(inform, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(inform->status));
		if (WIFEXITED(inform->status))
		{
			inform->status = WEXITSTATUS(inform->status);
			if (inform->status == 126)
			{
				print_error(inform, "Permission denied\n");
			}
		}
	}
}