#include "main.h"
/**
 * exec_cmd - Execute command
 * @tokens: Command to execute
 * @argv: argument vector
 * @env: environment variable
 *
 * Return: return no value
 */

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
		free_token_array(tokens);/*free(prog_path);*/
		perror("Error-cmd-path");
		/*exit(127);*/
	}
	return (0);
}
