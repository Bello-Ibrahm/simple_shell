#include "main.h"
/**
 * exec_cmd - Execute command
 * @args: Command to execute
 * @argv: argument vector
 * @env: environment variable
 *
 * Return: return no value
 */

int  exec_cmd(char **args, char **argv, char **env)
{
	int status, ret = 0;
	char *path, *cmd_path;
	pid_t  pid;

	path = _getpath("PATH");
	cmd_path = proc_path(args, path);
	if (cmd_path != NULL)
	{
		signal(SIGINT, signal_handler2);
		pid = fork();
		if (pid < 0)
		{
			write(2, "Fork error", 10);
			free(path), free(cmd_path), exit(-1);
		}
		if (pid == 0)
		{
			if (execve(cmd_path, args, env) == -1)
			{
				_error("%s: No such file or directory \n", argv), ret = -1;
			}
		}
		else if (pid > 0)
		{
			do {
				waitpid(pid, &status, WUNTRACED);
				signal(SIGINT, signal_handler);
				/*free(cmd_path);*/
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	else
	{
		perror("Error-cmd-path");
		free(cmd_path);
	}
	free(path), free_token_array(args);
	return (ret);

}
