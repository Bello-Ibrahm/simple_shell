#include "main.h"

/**
* main - Main program
* @argc: Argument count
* @argv: Argument vector
*
* Return: This will be returned by the shell program
*/

int main(int argc, char **argv)
{
	char *line;
	char **tokens;
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
			if (strcmp(tokens[0], "exit") == 0 || strcmp(tokens[0], "quit") == 0)
			{
				free(line), free(tokens);
				line = NULL, tokens = NULL;
				write(1, "\n", 1);
				break;
			}
			if (tokens != NULL)
			{
				exec_cmd(tokens, argv);
				free(tokens);
				free(line);
				line = NULL, tokens = NULL;
			}
		}
		free(line);
		line = NULL;
	}
	return (0);
}
