#include "main.h"
/**
 * print_environment - print env
 * Description: print environment variables
 * Return: void
 */
void print_environment(void)
{
	char **env = environ;

	char *line;

	while (*env != NULL)
	{
		line = *env;

		while (*line != '\0')
		{
			_putchar(*line);
			line++;
		}
		*line = '\0';
		_putchar('\n');
		env++;
	}
}
