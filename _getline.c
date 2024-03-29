#include "main.h"
/**
 * _getline - This get the user input
 *
 * Return: It return the user command
 */

char *_getline(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t n_byte;

	n_byte = getline(&line, &n, stdin);
	if (n_byte < 0)
	{
		free(line);
		/*perror("Error");*/
		return (NULL);
	}
	if (line[n_byte] == '\n')
		line[n_byte] = '\0';
	return (line);
}
