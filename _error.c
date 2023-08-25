#include "main.h"

/**
 * _error - Function to print out message
 * @msg: Message to display
 * @argv: Argument vector to catch program name
 * Return: No return value
 */
void _error(char *msg, char **argv)
{
	_puts(argv[0]);
	_puts(": ");
	_puts(msg);
}

/**
 * err_msg - Printing custom error message to stderr
 * @fd: File descriptor
 * @num_cmd: Number of commands written so far
 * @s1: First string - name of program
 * @s2: Name of command
 * @s3: custom message to be printed
 * Return: Void
 */

void err_msg(int fd, int num_cmd, char *s1, char *s2, char *s3)
{
	char num_stat;
	int temp = num_cmd;

	while (*s1)
	{
		write(fd, &(*s1), 1), s1++;
	}
	write(fd, ": ", 2);

	if (num_cmd < 10)
	{
		num_stat = num_cmd + '0';
		write(fd, &(num_stat), 1);
	}
	else
	{
		num_stat = (num_cmd / 10) + '0';
		write(fd, &(num_stat), 1);
		num_stat = (temp % 10) + '0';
		write(fd, &(num_stat), 1);
	}
	write(fd, ": ", 2);

	while (*s2)
		write(fd, &(*s2), 1), s2++;

	write(2, ": ", 2);

	while (*s3)
		write(fd, &(*s3), 1), s3++;

	write(fd, "\n", 1);
}
