#include "main.h"
/**
 * _strcat - strcat function
 * Description: Append string of pointers
 * @des: pointer to the destination
 * @src: string
 */

void _strcat(char *des, const char *src)
{
	while (*des != '\0')
	{
		des++;
	}
	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
}
