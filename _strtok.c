#include "main.h"
/**
 * _strtok - breaks string into tokens
 * @p: string
 * @tokens: delimiters
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
}
