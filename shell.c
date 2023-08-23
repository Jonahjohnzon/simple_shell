#include "shell.h"

/**
 * chek - chek
 * @sn: input
 */
void chek(int sn)
{
	if (sn == SIGINT)
	{
		_print_word("\n#cisfun$ ");
	}
}

/**
* _EOF - End of File
* @l: input
* @buff: input
 */
void _EOF(int l, char *buff)
{
	(void)buff;
	if (l == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_print_word("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _isattiy_ - check
  */

void _isatty_(void)
{
	if (isatty(STDIN_FILENO))
	{
		_print_word("#cisfun$ ");
	}
}
/**
 * main - main
 * Return: 0 on success
 */

int main(void)
{
	ssize_t len = 0;

	char *buff = NULL, *value, *path, **arvg;

	size_t size = 0;

	list_p *head = '\0';
	void (*f)(char **);

	signal(SIGINT, chek);
	while (len != EOF)
	{
		_isatty_();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arvg = _strtok(buff, " \n");
		if (!arvg || !arvg[0])
		{
			_exec(arvg);
		}
		else
		{
			value = _getenv("PATH");
			head = linkp(value);
			path = _which(arvg[0], head);
			f = _checkers(arvg);
			if (f)
			{
				free(buff);
				f(arvg);
			}
			else if (!path)
				_exec(arvg);
			else if (path)
			{
				free(arvg[0]);
				arvg[0] = path;
				_exec(arvg);
			}
		}
	}
	free_l(head);
	freearvg(arvg);
	free(buff);
	return (0);
}
