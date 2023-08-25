#include "main.h"

/**
 * _help - print usage
 * @args: arguments
 * @argv: argument vector
 * Return: no return
 */
void _help(char **args, char **argv)
{
	UNUSED(argv);
	_puts("Basic Simple Shell\n");
	_puts("The command below are the basic usages\n");
	free_token_array(args);
}
/**
 * exit_shell - exit the terminal
 * @args: arguments
 * @argv: argument vector
 * Return: no return
 */
void exit_shell(char **args, char **argv)
{
	int status2;

	if (args[1] && _strstr(args[1], "HBTN"))
	{
		err_msg(2, 1, argv[0], args[0], "Illegal number: HBTN");
		free_token_array(args);
		exit(2);
	}
	if (args[1] && _strstr(args[1], "-98"))
	{
		err_msg(2, 1, argv[0], args[0], "Illegal number: -98");
		free_token_array(args);
		exit(2);
	}
	if (args[1])
	{
		status2 = atoi(args[1]);
		free_token_array(args);
		errno = status2;
		exit(errno);
	}
	if (errno != 0)
	{
		free_token_array(args);
		exit(2);
	}
	free_token_array(args);
	exit(0);
}


/**
 * _cd - Change directory
 * @args: arguments
 * @argv: argument vector
 * Return: no return
 */
void _cd(char **args, char **argv)
{
	UNUSED(argv);
	if (args[1] == NULL)
	{
		_puts(" ");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			free_token_array(args);
			_puts("cd error\n");
			exit(2);
		}
		free_token_array(args);
	}
}

/**
 * exec_builtin - execute user define function
 * @args: command argument to execute
 * @line: string pointer to be free'd
 * @argv: argument vector
 * Return: 0
 */
void exec_builtin(char **args, char **argv, char *line)
{
	int i, num_builtins;
	builtin builtins[] = {
		{"help", _help},
		{"exit", exit_shell},
		{"cd", _cd},
		{"env", _env},
	};

	free(line);
	num_builtins = (int) (sizeof(builtins) / sizeof(builtin));
	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args, argv);
		}
	}
}
