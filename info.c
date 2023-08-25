#include "shell.h"

/**
 * cl_info - initialize
 * @inform: input
 */
void cl_info(info_table *inform)
{

	inform->args = NULL;
	inform->argvv = NULL;
	inform->pathe = NULL;
	inform->argcs = 0;
}


/**
 * set_inf -set info
 * @inform : input
 * @av: input
 */
void set_inf(info_table *inform, char **av)
{
	int i = 0;

	inform->fnames = av[0];
	if (inform->args)
	{
		inform->argvv = strtow(inform->args, " \t");
		if (!inform->argvv)
		{
		inform->argvv = malloc(sizeof(char *) * 2);
			if (inform->argvv)
			{
			inform->argvv[0] = _strdup(inform->args);
			inform->argvv[1] = NULL;

			}
		}
		for (i = 0; inform->argvv && inform->argvv[i]; i++)
			;
		inform->argcs = i;

		r_alias(inform);

		r_vars(inform);
	}
}

/**
 * free_info - frees info_t struct fields
 * @inform: input
 * @all: input
 *
 */
void free_info(info_table *inform, int all)
{
	ffree(inform->argvv);
	inform->argvv = NULL;
	inform->pathe = NULL;
	if (all)
	{
		if (!inform->cmd_buff)
		{
			free(inform->args);
		}
		if (inform->envi)
		{
			free_list(&(inform->envi));
		}
		if (inform->historys)
		{
			free_list(&(inform->historys));
		}
		if (inform->alias)
		{
			free_list(&(inform->alias));
		}
		ffree(inform->enviro);
		{
			inform->enviro = NULL;
		}
		_free((void **)inform->cmd_buff);

		if (inform->readfdd > 2)
		{
			close(inform->readfdd);
		}
		_putchar(B_FLUSH);
	}
}
