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
	free_token_array(args);
	exit(0);
	/*l = _atoi(args[1]);
	if (l == 98)
	{
		free_token_array(args);
		exit(98);
	}
	if (args[1] && _strstr(args[1], "HBTN"))
	{
		_puts("Illegal number: HBTN\n");
		free_token_array(args);
		errno = 2;
		exit(errno);
	}
	if (args[1] && _strstr(args[1], "-98"))
	{
		_puts("Illegal number: -98\n");
		free_token_array(args);
		errno = 2;
		exit(errno);
	}
	else
	{
		free_token_array(args);
		exit(0);
	}
	*/
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
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
		}
	}
}
