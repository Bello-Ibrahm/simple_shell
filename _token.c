#include "main.h"
/**
 * _token - Parse user command
 * @line_arg: argument to parse
 *
 * Return: Return the command to fork
 */
char **_token(char *line_arg)
{
	int buff_size, len = 0;
	char *token, **token2, *delim = " \t\n\r";

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

	/*
	int len = 0, buff_size = 16;
	char *token, **tokens;
	char *delim = " \t\r\n";

	tokens = malloc(sizeof(char *) * buff_size);
	if (!tokens)
	{
		perror("Error-2 :");
		exit(1);
	}
	token = strtok(line_arg, delim);
	while (token != NULL)
	{
		tokens[len] = token;
		len++;

		if (len >= buff_size)
		{
			buff_size = (int)(buff_size * 1.5);
			tokens = realloc(tokens, buff_size * sizeof(char *));
			if (!tokens)
			{
				perror("Error-3: ");
				exit(1);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[len] = NULL/
	return (tokens);
	*/

}
