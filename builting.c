#include "shell.h"

/**
 * _mexit - exit
 * @inform: input
 *  Return: int
 */
int _mexit(info_table *inform)
{
	int exitc;

	if (inform->argv[1])
	{
		exitc = _eratoi(inform->argv[1]);
		if (exitc == -1)
		{
			inform->status = 2;
			print_err(inform, "Illegal number: ");
			_errputs(inform->argv[1]);
			_errputchar('\n');
			return (1);
		}
		inform->err_num = _eratoi(inform->argv[1]);

		return (-2);
	}
	inform->err_num = -1;

	return (-2);
}

/**
 * _mcd - change dir
 * @inform: input
 *  Return: int
 */
int _mcd(info_table *inform)
{
	char *s, *dirt, buff[1024];
	int chdir_r;

	s = getcwd(buff, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inform->argv[1])
	{
		dirt = _getenv(inform, "HOME=");
		if (!dirt)
			chdir_r = /* TODO: what? */
				chdir((dirt = _getenv(inform, "PWD=")) ? dirt : "/");
		else
			chdir_r = chdir(dirt);
	}
	else if (_strcmp(inform->argv[1], "-") == 0)
	{
		if (!_getenv(inform, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inform, "OLDPWD=")), _putchar('\n');
		chdir_r = /* TODO: */
			chdir((dirt = _getenv(inform, "OLDPWD=")) ? dirt : "/");
	}
	else
		chdir_r = chdir(inform->argv[1]);
	if (chdir_r == -1)
	{
		print_err(inform, "can't cd to ");
		_errputs(inform->argv[1]), _errputchar('\n');
	}
	else
	{
		_setenv(inform, "OLDPWD", _getenv(inform, "PWD="));
		_setenv(inform, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
 * _mhelp - help
 * @inform: input
 *  Return: int
 */
int _mhelp(info_table *inform)
{
	char **a_array;

	a_array = inform->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
	{
		_puts(*a_array);
	}
	return (0);
}
