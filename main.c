#include "main.h"

/**
* main - Main program
* @argc: Argument count
* @argv: Argument vector
*
* Return: This will be returned by the shell program
*/

int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	char **tokens = NULL;
	int mode;

	signal(SIGINT, signal_handler);
	UNUSED(argc);
	mode = isatty(0);
	while (1)
	{
		if (mode == 1)
			printf("Bello >>> $ ");

		/*printf(">>> $ ");*/
		line = _getline();
		if (line != NULL)
		{
			tokens = _token(line);
			if (tokens[0] == NULL || tokens == NULL)
			{
				free(line), free_token_array(tokens);
				continue;
			}
			if (_strcmp(tokens[0], "exit") == 0 || _strcmp(tokens[0], "quit") == 0)
			{
				free_token_array(tokens);
				exit(0);
			}
			exec_cmd(tokens, argv, env);
			/*free_token_array(tokens);*/
			continue;
		}
		free(line);
	}
	return (0);
}
