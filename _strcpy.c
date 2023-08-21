#include "main.h"
/**
 * _strcpy - strcpy function
 * Description: copy strings pointed to.
 * @src: string
 * @des: pointer destination
 */

void _strcpy(char *des, const char *src)
{
	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}

	*des = '\0';
}
