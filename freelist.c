#include "shell.h"
/**
 * free_l - frees
 *@head: input
 */
void free_l(list_p *head)
{
	list_p *stor;

	while (head)
	{
		stor = head->p;
		free(head->dir);
		free(head);
		head = stor;
	}

}
