#include "shell.h"

/**
 * main - main functions
 * @a: input
 * @av: input
 *
 * Return: int
 */
int main(int a, char **av)
{
	info_table inform[] = { INFO_INIT };
	int f = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (f)
		: "r" (f));

	if (a == 2)
	{
		f = open(av[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			if (errno == ENOENT)
			{
				_errputs(av[0]);
				_errputs(": 0: Can't open ");
				_errputs(av[1]);
				_errputchar('\n');
				_errputchar(B_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inform->readfdd = f;
	}
	read_event(inform);
	env_list(inform);
	_app(inform, av);
	return (EXIT_SUCCESS);
}
