#include "main.h"
/**
 * _strtok - strtok function
 * Description: Breaks strings into series of tokens
 * @p: string
 * @tokens: C string of the delimiters
 */
void _strtok(char *p, char **tokens)
{
	char *delim = " ";

	int tokenCount = 0;
	char *token = strtok(p, delim);

	while (token != NULL && tokenCount < 200)
	{
		tokens[tokenCount] = token;
		tokenCount++;
		token = strtok(NULL, delim);
	}
	tokens[tokenCount] = NULL;

	return (0);
}
