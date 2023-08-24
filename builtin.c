#include "main.h"

/**
 * _help - print usage
 * @args: arguments
 *
 * Return: no return
 */
void _help(char **args)
{
<<<<<<< HEAD
	/*UNUSED(args);*/
	_puts("Basic Simple Shell\n");
	_puts("The command below are the basic usages\n");
	free_token_array(args);
=======
	UNUSED(args);
	_puts("Basic Simple Shell\n");
	_puts("The command below are the basic usages\n");
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
}
/**
 * exit_shell - exit the terminal
 * @args: arguments
 *
 * Return: no return
 */
void exit_shell(char **args)
{
<<<<<<< HEAD

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
=======
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
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
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
<<<<<<< HEAD
		_puts(" ");
=======
		_puts("No argument specified\n");
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
	}
	else
	{
		if (chdir(args[1]) != 0)
<<<<<<< HEAD
		{
			free_token_array(args);
			_puts("cd error\n");
			/*errno = 2;*/
			exit(errno);
		}
	}
	free_token_array(args);
=======
			_puts("cd error\n");
	}
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
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
<<<<<<< HEAD
		if (_strcmp(args[0], builtins[i].name) == 0)
=======
		if (strcmp(args[0], builtins[i].name) == 0)
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
		{
			builtins[i].func(args);
		}
	}
<<<<<<< HEAD
	/*free_token_array(args);*/
=======
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
}
