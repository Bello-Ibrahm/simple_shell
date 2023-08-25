#include "main.h"
/**
 * _env - Print the environment variables
 * @args: command arguments
 * @argv: argument vector
 * Return: no return
 */
void _env(char **args, char **argv)
{
	int i = 0;

	UNUSED(args);
	UNUSED(argv);
	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
