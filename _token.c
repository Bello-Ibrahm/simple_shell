#include "main.h"
/**
 * _token - tokenize user command
 * @line_arg: argument to parse
 *
 * Return: Return the token argument
 */
char **_token(char *line_arg)
{
	int buff_size, len = 0;
	char *token, **token2, *delim = " \'\"\t\n\r";

	buff_size = count_words(line_arg);
	if (buff_size == 0)
	{
		return (NULL);
	}
	token = strtok(line_arg, delim);
	token2 = malloc(sizeof(char *) * (buff_size + 1));

	while (token != NULL)
	{
		token2[len] = malloc(sizeof(char) * (_strlen(token) + 1));
		token2[len] = _strcpy(token2[len], token);
		token = strtok(NULL, delim);
		len++;
	}
	token2[len] = NULL;
	return (token2);
}
