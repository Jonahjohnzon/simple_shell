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
	char *token = _stringtok(p, delim);

	while (token != NULL && tokenCount < 200)
	{
		tokens[tokenCount] = token;
		tokenCount++;
		token = _stringtok(NULL, delim);
	}
	tokens[tokenCount] = NULL;
}
