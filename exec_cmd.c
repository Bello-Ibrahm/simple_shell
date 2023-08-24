#include "main.h"

void run_execve(char **tokens, char **argv, char **env);

/**
 * exec_cmd - Execute command
 * @tokens: tokenize command
 * @argv: argument vector
 * @line: string from getline
 * @env: environment variable
 *
 * Return: No return value
 */

void  exec_cmd(char **tokens, char **argv, char *line, char **env)
{
	if (_strcmp(tokens[0], "exit") == 0 || _strcmp(tokens[0], "cd") == 0 ||
			_strcmp(tokens[0], "help") == 0 || _strcmp(tokens[0], "env") == 0)
		exec_builtin(tokens, line);
	else
	{
		free(line);
		/*comment_handler(tokens);*/
		run_execve(tokens, argv, env);
	}
}

/**
 * run_execve - Run the execution with the execve
 * @tokens: the tokenize command
 * @argv: argument vector
 * @env: environment variable
 *
 * Return: no return.
 */
void run_execve(char **tokens, char **argv, char **env)
{
	char *prog_path;
	int status;
	pid_t pid;

	prog_path = proc_path(tokens, _getpath("PATH"));
	if (prog_path != NULL)
	{
		signal(SIGINT, signal_handler2);
		pid = fork();
		if (pid < 0)
		{
			free(prog_path), free_token_array(tokens);
			write(2, "fork error", 10);
			exit(-1);
		}
		if (pid == 0)
		{
			if (execve(prog_path, tokens, env) == -1)
			{
				free(prog_path), free_token_array(tokens);
				_exit(-1);
			}
		}
		else if (pid > 0)
		{
			do {
				waitpid(pid, &status, WUNTRACED);
				signal(SIGINT, signal_handler);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
	{
		free(prog_path);
		perror(argv[0]);
		exit(127);
	}
	free(prog_path), free_token_array(tokens);
}
