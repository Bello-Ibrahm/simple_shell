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

	UNUSED(env);
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
			tokens = _token(line);
			/*comment_handler(tokens);*/
			if (tokens[0] == NULL || tokens == NULL)
			{
				free(line), free_token_array(tokens);
			}
			else
			{
<<<<<<< HEAD
				exec_cmd(tokens, argv, line, env);
			}
		}
		else
			exit(127);
=======
				if (
					_strcmp(tokens[0], "exit") == 0
					|| _strcmp(tokens[0], "cd") == 0
				       || _strcmp(tokens[0], "help") == 0)
				{
					exec_builtin(tokens, line);
				}
				else
					exec_cmd(tokens, argv, env);
			}
		}
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
	}
	return (0);
}
