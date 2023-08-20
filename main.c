#include "main.h"

/**
* main - Main program
* @argc: Argument count
* @argv: Argument vector
* @env: environment variable
*
* Return: This will be returned by the shell program
*/

int main(int argc, char **argv, char **env)
{
	char *line = NULL, *prompt = "$ ";
	char **tokens = NULL;
	int mode;

	if (argc > 1 || argv == NULL)
		write(2, "Please run with no arguments\n", 29), exit(127);
	signal(SIGINT, signal_handler);
	/* Handle Non-interactive mode */
	mode = isatty(0);
	while (1)
	{
		if (mode == 1)
			write(STDOUT_FILENO, prompt, 2);
		line = _getline();
		if (line != NULL)
		{
			tokens = _token(line);
			comment_handler(tokens);
			if (tokens[0] == NULL || tokens == NULL)
			{
				free(line), free_token_array(tokens);
				continue;
			}
			if (_strcmp(tokens[0], "exit") == 0 || _strcmp(tokens[0], "quit") == 0)
			{
				free(line), free_token_array(tokens), exit(0);
			}
			if (exec_cmd(tokens, argv, env) == -1)
			{
				free(line), free_token_array(tokens);
				continue;
			}
			else
			{
				free(line);
				continue;
			}
		}
	}
	return (0);
}
