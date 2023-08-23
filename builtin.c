#include "main.h"

/**
 * _help - print usage
 * @args: arguments
 *
 * Return: no return
 */
void _help(char **args)
{
	UNUSED(args);
	_puts("Basic Simple Shell\n");
	_puts("The command below are the basic usages\n");
}
/**
 * exit_shell - exit the terminal
 * @args: arguments
 *
 * Return: no return
 */
void exit_shell(char **args)
{
	int l;

	l = _atoi(args[1]);
	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
	{
		free_token_array(args);
		exit(0);
	}
	else if (_strcmp(args[0], "exit") == 0 && (l == 98))
	{
		free_token_array(args);
		exit(98);
	}
}


/**
 * _cd - Change directory
 * @args: arguments
 *
 * Return: no return
 */
void _cd(char **args)
{
	if (args[1] == NULL)
	{
		_puts("No argument specified\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
			_puts("cd error\n");
	}
}

/**
 * exec_builtin - execute user define function
 * @args: command argument to execute
 * @line: string pointer to be free'd
 *
 * Return: 0
 */
void exec_builtin(char **args, char *line)
{
	int i, num_builtins;
	builtin builtins[] = {
		{"help", _help},
		{"exit", exit_shell},
		{"cd", _cd},
	};

	free(line);
	num_builtins = (int) (sizeof(builtins) / sizeof(builtin));
	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
		}
	}
}
