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

	UNUSED(path);
	/*path = _getpath("PATH");*/
	cmd_path = proc_path(args, _getpath("PATH"));
	if (cmd_path != NULL)
	{
		signal(SIGINT, signal_handler2);
		pid = fork();
		if (pid == 0)
		{
			if (execve(cmd_path, args, env) == -1)
			{
				_error("%s: No such file or directory \n", argv), ret = -1;
			}
			/*free(path), free(cmd_path);*/
		}
		else if (pid > 0)
		{
			do {
				/*free(cmd_path);*/
				waitpid(pid, &status, WUNTRACED);
				signal(SIGINT, signal_handler);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		else
			write(2, "Fork error", 10);
	}
	else
	{
		perror("Error-cmd-path"), exit(127);
	}
	/*free(path)*/
	free(cmd_path), free_token_array(args);
	return (ret);
}
