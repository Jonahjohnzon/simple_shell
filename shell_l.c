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
		cl_info(inform);
		if (interactive(inform))
		{
			_puts("$ ");
		}
		_errputchar(B_FLUSH);
		r = _input(inform);
		if (r != -1)
		{
			set_inf(inform, a);
			built_ret = find_built(inform);
			if (built_ret == -1)
			{
				find_c(inform);
			}
		}
		else if (interactive(inform))
			_putchar('\n');
		free_info(inform, 0);
	}
	write_history_event(inform);
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
	built_table builtintbl[] = {
		{"exit", _mexit},
		{"env", _env},
		{"setenv", _seten},
		{"unsetenv", _unseten},
		{"help", _mhelp},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(inform->argvv[0], builtintbl[i].type) == 0)
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

	inform->pathe = inform->argvv[0];
	if (inform->linecount_flag == 1)
	{
		inform->line_count++;
		inform->linecount_flag = 0;
	}
	for (i = 0, k = 0; inform->args[i]; i++)
		if (!is_delim(inform->args[i], " \t\n"))
			k++;
	if (!k)
	{
		return;
	}

	pathe = _path(inform, _getenv(inform, "PATH="), inform->argvv[0]);
	if (pathe)
	{
		inform->pathe = pathe;
		fork_c(inform);
	}
	else
	{
		if ((interactive(inform) || _getenv(inform, "PATH=")
			|| inform->argvv[0][0] == '/') && _cmd(inform, inform->argvv[0]))
			fork_c(inform);
		else if (*(inform->args) != '\n')
		{
			inform->status = 127;
			print_err(inform, "not found\n");
		}
	}
}

/**
 * fork_c - fork cmd
 * @inform: input
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
		if (execve(inform->pathe, inform->argvv, get_envi(inform)) == -1)
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
				print_err(inform, "Permission denied\n");
			}
		}
	}
}
