#include "main.h"

void run_execve(char **tokens, char **argv, char **env);

/**
 * exec_cmd - Execute command
<<<<<<< HEAD
 * @tokens: tokenize command
=======
 * @tokens: Command to execute
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
 * @argv: argument vector
 * @line: string from getline
 * @env: environment variable
 *
 * Return: No return value
 */

<<<<<<< HEAD
void  exec_cmd(char **tokens, char **argv, char *line, char **env)
{
	if (_strcmp(tokens[0], "exit") == 0 || _strcmp(tokens[0], "cd") == 0 ||
			_strcmp(tokens[0], "help") == 0)
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
			perror("Fork error");
			exit(-1);
		}
		if (pid == 0)
		{
			if (execve(prog_path, tokens, env) == -1)
			{
				free(prog_path), free_token_array(tokens);
				_error("%s: execve error\n", argv);
				exit(-1);
			}
		}
		else if (pid > 0)
		{
=======
int  exec_cmd(char **tokens, char **argv, char **env)
{
	int status;
	char *path, *prog_path;
	pid_t  pid;

	UNUSED(path);
	prog_path = proc_path(tokens, _getpath("PATH"));
	if (prog_path != NULL)
	{
		signal(SIGINT, signal_handler2);
		pid = fork();
		if (pid == 0)
		{
			if (execve(prog_path, tokens, env) == -1)
			{
				_error("%s: No such file or directory \n", argv);
				free_token_array(tokens), free(prog_path);
			}
			/*free_token_array(tokens), free(prog_path);*/
		}
		else if (pid > 0)
		{
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
			do {
				waitpid(pid, &status, WUNTRACED);
				signal(SIGINT, signal_handler);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		else
			write(2, "Fork error", 10);
		free_token_array(tokens);
	}
	else
	{
<<<<<<< HEAD
		free(prog_path);
		perror("Error-cmd-path");
		errno = 127;
	}
	free(prog_path), free_token_array(tokens);
=======
		free_token_array(tokens);/*free(prog_path);*/
		perror("Error-cmd-path");
		/*exit(127);*/
	}
	return (0);
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
}
