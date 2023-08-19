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
	pid_t  pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
	}
	if (pid == 0)
	{
		if (execve(args[0], args,  env) == -1)
		{
			_error("%s: No such file or directory \n", argv);
			ret = -1;
		}
	}
	else if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
			free_token_array(args);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (ret);

}
