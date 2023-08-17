#include "main.h"
/**
 * exec_cmd - Execute command
 * @arg: Command to execute
 * @argv: argument vector
 *
 * Return: return no value
 */

void  exec_cmd(char **args, char **argv, char **env)
{
	int status;
	pid_t  pid;


	pid = fork();

	if (pid < 0)
	{
		perror("Error");
	}
	if (pid == 0)
	{
		/*execvp(arg[0], arg);*/
		if (execve(args[0], args, env) == -1)
		{
			free_token_array(args);
			_error("%s: No such file or directory\n", argv);
			/*return;*/
		}
	}
	else if (pid > 0)
	{
		do {
			free_token_array(args);
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

}
