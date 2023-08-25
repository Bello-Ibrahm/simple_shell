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
	char *line = NULL, *prompt = ">> $ ", **tokens = NULL;
	int mode;

	if (argc > 1 || argv == NULL)
		write(2, "Please run with no arguments\n", 29), exit(127);
	signal(SIGINT, signal_handler);
	/* Handle Non-interactive mode */
	mode = isatty(0);
	while (1)
	{
		if (mode == 1)
			write(STDOUT_FILENO, prompt, 5);
		line = _getline();
		if (line != NULL)
		{
			/*fix_cmt(line);*/
			tokens = _token(line);
			if (tokens[0] == NULL || tokens == NULL)

			{
				free(line), free_token_array(tokens);
			}
			else
			{
				exec_cmd(tokens, argv, line, env);
			}
		}
		else
		{
			exit(0);
		}
	}
	return (0);
}
