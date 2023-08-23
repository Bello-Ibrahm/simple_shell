#include "main.h"

/**
 * _error - Function to print out message
 * @msg: Message to display
 * @argv: Argument vector to catch program name
 * Return: No return value
 */
void _error(char *msg, char **argv)
{
	fprintf(stderr, msg, argv[0]);
}

/**
  * errmsg - function to print corresponding error
  * @err: number of error
  * @cmd: command inputted
  * @argv: argument vector
  * Return: void
**/
void _errmsg(int err, char **cmd, char **argv)
{
	if (err == 2)
	{
		_puts(argv[0]);
		_puts(cmd[0]);
		_puts(": command not found\n");
	}
	if (err == 126)
	{
		_puts(cmd[0]);
		_puts(": Required key not available\n");
		exit(err);
	}
	if (err == 127)
	{
		_puts(cmd[0]);
		_puts(": Key has expired\n");
		exit(err);
	}
	if (err == 1)
	{
		exit(EXIT_SUCCESS);
	}

}
