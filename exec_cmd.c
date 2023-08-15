#include "main.h"
/**
 * exec_cmd - Execute command
 * @arg: Command to execute
 * @argv: argument vector
 *
 * Return: return no value
 */

void exec_cmd(char **arg, char **argv)
{
	int status;
	pid_t  pid;

	pid = fork();

	if (pid == 0)
	{
		execvp(arg[0], arg);
		_error("%s: No such file or directory\n", argv);
		free(arg);
		arg = NULL;
		exit(1);
	}
	else if (pid > 0)
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error-1: ");
	}


}
