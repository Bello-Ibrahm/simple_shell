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
<<<<<<< HEAD
		/*perror("getline error: ");*/
		free(line);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
=======
		free(line);
		perror("getline error: ");
		/*
		 * if (isatty(STDIN_FILENO) != 0)
		 *	write(STDOUT_FILENO, "\n", 1);
		*/
		exit(1);
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
	}
	if (line[n_byte] == '\n')
		line[n_byte] = '\0';
	return (line);
}
