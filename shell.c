#include "shell.h"

/**
 * chek - chek
 * @sn: input
 */
void chek(int sn)
{
	if (sum == SIGINT)
	{
		_print_word("\n#cisfun$ ");
	}
}

/**
* _EOF - End of File
* @l: input
* @buff: input
 */
void _EOF(int len, char *buff)
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

	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_isatty_();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitstring(buff, " \n");
		if (!arvg || !arvg[0])
		{
			execute(arvg);
		}
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arvg[0], head);
			f = checkerss(arvg);
			if (f)
			{
				free(buff);
				f(arvg);
			}
			else if (!path)
				execute(arvg);
			else if (path)
			{
				free(arvg[0]);
				arvg[0] = path;
				execute(arvg);
			}
		}
	}
	freearvg(arvg);
	free(buff);
	return (0);
}
