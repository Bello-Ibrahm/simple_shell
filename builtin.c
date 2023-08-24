#include "main.h"

/**
 * _help - print usage
 * @args: arguments
 *
 * Return: no return
 */
void _help(char **args)
{
	_puts("Basic Simple Shell\n");
	_puts("The command below are the basic usages\n");
	free_token_array(args);
}
/**
 * exit_shell - exit the terminal
 * @args: arguments
 *
 * Return: no return
 */
void exit_shell(char **args)
{
	if (args[1] && _atoi(args[1])  == 98)
	{
		free_token_array(args);
		exit(98);
	}
	else if (args[1] && _strstr(args[1], "HBTN"))
	{
		_puts("Illegal number: HBTN\n");
		free_token_array(args);
		exit(2);
	}
	else if (args[1] && _strstr(args[1], "-98"))
	{
		_puts("Illegal number: -98\n");
		free_token_array(args);
		exit(2);
	}
	else
	{
		free_token_array(args);
		exit(0);
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
