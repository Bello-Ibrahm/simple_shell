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
