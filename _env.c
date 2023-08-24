#include "main.h"

/**
 * _env - Print the environment variables
 * @args: command arguments
 * Return: no return
 */
void _env(char **args)
{
	int i = 0;

	UNUSED(args);
	if (environ != NULL)
	{
		while (environ[i] != NULL)
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		write(2, "Environment is Null, Can't Print it\n", 36);
	}
}
