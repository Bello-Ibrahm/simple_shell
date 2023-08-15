#include "main.h"
/**
 * _token - Parse user command
 * @line_arg: argument to parse
 *
 * Return: Return the command to fork
 */
char **_token(char *line_arg)
{
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
	tokens[len] = NULL;
	return (tokens);

}
